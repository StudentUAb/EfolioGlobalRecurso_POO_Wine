#include <iostream>
#include <fstream>
#include <algorithm>
#include "adega.h"
#include "vinho.h"

double calcularMediaTipo(std::vector<Vinho> vinhos, const std::string& tipo) {
    double soma = 0.0;
    int count = 0;
    for (const auto& vinho : vinhos) {
        if (vinho.getTipo() == tipo) {
            soma += vinho.getVolAlcool();
            count++;
        }
    }
    return count != 0 ? soma / count : 0;
}

void gravarSuaves(const std::vector<Vinho> &vinhos, double media, const std::string &nomeFicheiro) {
    std::ofstream file(nomeFicheiro, std::ios::app);
    if (file.is_open()) {
        for (auto &vinho : vinhos) {
            if (vinho.getVolAlcool() < media) {
                file << vinho.getNome() << "\n";
            }
        }
        file.close();
    } else {
        std::cout << "Erro ao abrir o arquivo " << nomeFicheiro << "\n";
    }
}

void procurarRefeicao(std::vector<Adega> adegas, const std::string& refeicao) {
    std::cout << "*** Vinhos para acompanhar com: " << refeicao << " ***\n";
    for (const auto& adega : adegas) {
        for (const auto& vinho : adega.getVinhos()) {
            if (std::find(vinho.getRefeicoes().begin(), vinho.getRefeicoes().end(), refeicao) != vinho.getRefeicoes().end()) {
                std::cout << adega.getWeb() << "\n";
                break;
            }
        }
    }
}

int main() {

    Vinho v1("Vinho 1", "Maduro Tinto", {"Casta 1", "Casta 2"}, {"Peixe", "Queijo"}, 14.0);
    Vinho v2("Vinho 2", "Verde", {"Casta 3", "Casta 4"}, {"Peixe", "Queijo"}, 11.0);
    Vinho v3("Vinho 3", "Branco", {"Casta 5", "Casta 6"}, {"Peixe", "Fruta"}, 13.0);
    Vinho v4("Vinho 4", "Maduro Tinto", {"Casta 7", "Casta 8"}, {"Carne", "Queijo"}, 12.0);

    Adega a1("Adega 1", "Porto", "Portugal", "www.adega1.pt");
    a1.adicionarVinho(v1);
    a1.adicionarVinho(v4);

    Adega a2("Adega 2", "Lisboa", "Portugal", "www.adega2.pt");
    a2.adicionarVinho(v2);
    a2.adicionarVinho(v3);

    std::vector<Adega> adegas = {a1, a2};

    // Calcule a média de álcool e grave os vinhos suaves
    std::vector<Vinho> vinhos = {v1, v2, v3, v4};
    double media;
    
    for(auto & adega: adegas) {
        std::cout << adega;
        media = calcularMediaTipo(adega.getVinhos(), "Maduro Tinto");
        if(media == 0)
            std::cout << "Nao existem vinhos do tipo Maduro Tinto nesta adega!\n";
        std::cout << "\n\n";
    }
    
    media = calcularMediaTipo(vinhos, "Maduro Tinto");
    std::cout << "*** Media Total de todos os vinhos ***\n";
    std::cout << "Media de Volume de Vinhos Maduro Tinto: " << media << "\n";
    gravarSuaves(vinhos, media, "suaves.txt");

    procurarRefeicao(adegas, "Peixe");

    return 0;
}
