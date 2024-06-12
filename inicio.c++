#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Janela {
public:
    Janela() {
        RenderWindow window(VideoMode(800, 600), "Calculadora");

        // Carregar a fonte
        Font font;
        if (!font.loadFromFile("Fontes/Quick Delight.otf")) {
            cout << "Erro ao carregar a fonte!" << endl;
            return;
        }

        // Criação dos botões
        int btns = 9;
        vector<RectangleShape> buttons;
        vector<Text> buttonLabels;
        for (int i = 0; i < btns; i++) {
            RectangleShape button(Vector2f(60, 70));
            button.setFillColor(Color::White);
            button.setPosition(100 + (i % 3) * 90, 50 + (i / 3) * 90);
            buttons.push_back(button);

            Text label;
            label.setFont(font);
            label.setString(to_string(i + 1));
            label.setCharacterSize(24);
            label.setFillColor(Color::Black);

            FloatRect textRect = label.getLocalBounds();
            label.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            label.setPosition(button.getPosition().x + button.getSize().x / 2.0f, button.getPosition().y + button.getSize().y / 2.0f);
            buttonLabels.push_back(label);
        }

        // Botão 0
        RectangleShape button0(Vector2f(60, 70));
        button0.setFillColor(Color::White);
        button0.setPosition(190, 320);
        buttons.push_back(button0);

        Text label0;
        label0.setFont(font);
        label0.setString("0");
        label0.setCharacterSize(24);
        label0.setFillColor(Color::Black);

        FloatRect textRect0 = label0.getLocalBounds();
        label0.setOrigin(textRect0.left + textRect0.width / 2.0f, textRect0.top + textRect0.height / 2.0f);
        label0.setPosition(button0.getPosition().x + button0.getSize().x / 2.0f, button0.getPosition().y + button0.getSize().y / 2.0f);
        buttonLabels.push_back(label0);

        while (window.isOpen()) {
            Event evento;
            while (window.pollEvent(evento)) {
                if (evento.type == Event::Closed) {
                    window.close();
                }

                // Verificação de clique nos botões
                if (evento.type == Event::MouseButtonPressed) {
                    if (evento.mouseButton.button == Mouse::Left) {
                        for (int i = 0; i < buttons.size(); i++) {
                            if (isMouseOverButton(buttons[i], window)) {
                                cout << "Button " << (i == 9 ? 0 : i + 1) << " clicked!" << endl;
                            }
                        }
                    }
                }
            }

            window.clear(Color::Black);

            // Desenho dos botões
            for (int i = 0; i < buttons.size(); i++) {
                window.draw(buttons[i]);
                window.draw(buttonLabels[i]);
            }

            window.display();
        }
    }

private:
    bool isMouseOverButton(RectangleShape button, RenderWindow& window) {
        Vector2i mousePos = Mouse::getPosition(window);
        Vector2f buttonPos = button.getPosition();
        Vector2f buttonSize = button.getSize();

        return (mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x) &&
               (mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y);
    }
};

int main() {
    cout << "Calculadora!" << endl;
    int a = 0;
    while (a == 0) {
        Janela projeto;
        cout << "Digite 1 para sair ou 0 para continuar: ";
        cin >> a;
    }
    cout << "Até mais!" << endl;

    return 0;
}
