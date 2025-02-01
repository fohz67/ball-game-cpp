#pragma one

class Hotkeys {
  public:
    static std::string keyToString(sf::Keyboard::Key key) {
        switch (key) {
        case sf::Keyboard::A:
            return "A";
        case sf::Keyboard::B:
            return "B";
        case sf::Keyboard::C:
            return "C";
        case sf::Keyboard::D:
            return "D";
        case sf::Keyboard::E:
            return "E";
        case sf::Keyboard::F:
            return "F";
        case sf::Keyboard::G:
            return "G";
        case sf::Keyboard::H:
            return "H";
        case sf::Keyboard::I:
            return "I";
        case sf::Keyboard::J:
            return "J";
        case sf::Keyboard::K:
            return "K";
        case sf::Keyboard::L:
            return "L";
        case sf::Keyboard::M:
            return "M";
        case sf::Keyboard::N:
            return "N";
        case sf::Keyboard::O:
            return "O";
        case sf::Keyboard::P:
            return "P";
        case sf::Keyboard::Q:
            return "Q";
        case sf::Keyboard::R:
            return "R";
        case sf::Keyboard::S:
            return "S";
        case sf::Keyboard::T:
            return "T";
        case sf::Keyboard::U:
            return "U";
        case sf::Keyboard::V:
            return "V";
        case sf::Keyboard::W:
            return "W";
        case sf::Keyboard::X:
            return "X";
        case sf::Keyboard::Y:
            return "Y";
        case sf::Keyboard::Z:
            return "Z";
        case sf::Keyboard::Space:
            return "SPACE";
        case sf::Keyboard::Enter:
            return "ENTER";
        case sf::Keyboard::Escape:
            return "ESCAPE";
        case sf::Keyboard::LShift:
            return "LSHIFT";
        case sf::Keyboard::RShift:
            return "RSHIFT";
        case sf::Keyboard::LControl:
            return "LCTRL";
        case sf::Keyboard::RControl:
            return "RCTRL";
        case sf::Keyboard::LAlt:
            return "LALT";
        case sf::Keyboard::RAlt:
            return "RALT";
        case sf::Keyboard::Tab:
            return "TAB";
        case sf::Keyboard::Backspace:
            return "BACKSPACE";
        case sf::Keyboard::Delete:
            return "DELETE";
        case sf::Keyboard::Left:
            return "LEFT";
        case sf::Keyboard::Right:
            return "RIGHT";
        case sf::Keyboard::Up:
            return "UP";
        case sf::Keyboard::Down:
            return "DOWN";
        default:
            return "UNKNOWN";
        }
    }
};
