#pragma once
class Button {
private:
	int x, y, width, height;
	int extra;
	BtnAction action;
	bool disabled = false;
public:
	Button(int x, int y, int w, int h, BtnAction a, int e) {
		this->x = x;
		this->y = y;
		width = w;
		height = h;
		extra = e;
		action = a;
	}

	BtnAction GetAction() {
		return action;
	}

	int GetExtra() {
		return extra;
	}

	bool isOver(COORD pos) {
		if (pos.Y > y && pos.Y < y + height && pos.X < x + width && pos.X > x && !disabled) {
			return true;
		}
		else {
			return false;
		}
	}

	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

	bool isDisabled() {
		return disabled;
	}

	void Disable() {
		disabled = true;
	}

	void Enable() {
		disabled = false;
	}

	virtual void Draw(HANDLE out) = 0;
	virtual void DrawSelected(HANDLE out) = 0;
};

class TextButton: public Button {
private:
	std::string text;
public:
	TextButton(int x, int y, std::string t, BtnAction a, int e = 0) :Button(x, y, ((t.length() * 14) + (t.length()-1)*2 + 12), 15, a, e) {
		text = t;
	}

	void Draw(HANDLE out) {
		Sprites.DrawTextSprites(out, text, GetX() + 8, GetY() + 4);
	}

	void DrawSelected(HANDLE out) {
		Sprites.DrawSprite(Sprites.heartSprites, 0, 0, 14, 8, out, GetX() - 14, GetY() + 4);
	}
};

class CharacterButton : public Button {
private:
	Player_Info * file;
	bool displayHearts;
public:
	CharacterButton(int x, int y, Player_Info * f, int e, bool d = true) : Button(x, y, 326, 22, SELECT_FILE, e) {
		file = f;
		displayHearts = d;
	}

	void Draw(HANDLE out) {

		Sprites.DrawSprite(Sprites.playerSprites, 0, 0, 30, 16, out, GetX()+6, GetY()+3);
		if (file->file_exists) {
			Sprites.DrawTextSprites(out, file->Name + "-", GetX() + 52, GetY() + 2);
			if (displayHearts) {
				int numHearts = file->MaxLife / 2;
				for (int c = 0; c < numHearts; c++) {
					if (c < 8) {
						Sprites.DrawSprite(Sprites.heartSprites, 0, 0, 14, 8, out, GetX() + 194 + (c * 16), GetY() + 10);
					}
					else {
						Sprites.DrawSprite(Sprites.heartSprites, 0, 0, 14, 8, out, GetX() + 194 + ((c - 8) * 16), GetY() + 1);
					}
				}
			}
		}
		else {
			Sprites.DrawTextSprites(out, "        -", GetX() + 52, GetY() + 2);
		}
	}

	void DrawSelected(HANDLE out) {
		Sprites.DrawSprite(Sprites.heartSprites, 0, 0, 14, 8, out, GetX() - 14, GetY() + 8);
	}
};

class Menu {
private:
	int selected;
	std::vector<Button*> buttons;
public:
	Menu(std::vector<Button*> btns) {
		buttons = btns;
	}

	void Draw(HANDLE out) {
		for (int b = 0; b < buttons.size(); b++) {
			buttons[b]->Draw(out);
		}

		buttons[selected]->DrawSelected(out);
	}

	void SetSelected(int s) {
		selected = s;
	}

	int GetSelected() {
		return selected;
	}
	
	int GetNumButtons() {
		return buttons.size();
	}

	bool isOverBtn(COORD pos) {
		for (int b = 0; b < buttons.size(); b++) {
			if (buttons[b]->isOver(pos)) {
				selected = b;
				return true;
			}
		}

		return false;
	}

	BtnAction GetSelAction() {
		return buttons[selected]->GetAction();
	}

	int GetSelExtra() {
		return buttons[selected]->GetExtra();
	}

	void DisableButtons(std::vector<int> ids) {
		for (int i = 0; i < ids.size(); i++) {
			buttons[ids[i]]->Disable();
		}
	}

	void EnableButtons(std::vector<int> ids) {
		for (int i = 0; i < ids.size(); i++) {
			buttons[ids[i]]->Enable();
		}
	}
};