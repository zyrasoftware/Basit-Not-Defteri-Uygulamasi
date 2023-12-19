#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Notepad {
public:
    Notepad(const std::string& fileName) : fileName(fileName) {}

    void writeNote() {
        std::cout << "Notunuzu buraya yazın (Ctrl+D veya Ctrl+Z sona erdirir):" << std::endl;

        std::string note;
        std::cin.ignore(); // Önceki girişten kalan karakterleri temizle
        while (std::getline(std::cin, note)) {
            notes.push_back(note);
        }
    }

    void saveNote() {
        std::ofstream file(fileName);

        if (file.is_open()) {
            for (const auto& note : notes) {
                file << note << std::endl;
            }

            file.close();
            std::cout << "Notlarınız dosyaya kaydedildi." << std::endl;
        }
        else {
            std::cerr << "Hata: Dosya açılamadı!" << std::endl;
        }
    }

    void readNote() {
        std::ifstream file(fileName);

        if (file.is_open()) {
            std::string line;
            std::cout << "Notlarınız:" << std::endl;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }

            file.close();
        }
        else {
            std::cerr << "Hata: Dosya açılamadı!" << std::endl;
        }
    }

private:
    std::string fileName;
    std::vector<std::string> notes;
};

int main() {

    setlocale(LC_ALL, "Turkish");
    std::cout << "Basit Not Defteri Uygulaması" << std::endl;
    std::cout << "Lütfen notlarınızı kaydetmek için bir dosya adı belirtin: ";

    std::string fileName;
    std::cin >> fileName;

    Notepad notepad(fileName);

    notepad.writeNote();
    notepad.saveNote();
    notepad.readNote();

    return 0;
}
