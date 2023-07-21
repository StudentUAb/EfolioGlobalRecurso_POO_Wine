#include "adega.h"
#include <iostream>

Adega::Adega(const std::string &nome, const std::string &localidade, const std::string &pais, const std::string &web) 
    : nome(nome), localidade(localidade), pais(pais), web(web) {}

std::string Adega::getNome() const {
    return nome;
}

std::string Adega::getLocalidade() const {
    return localidade;
}

std::string Adega::getPais() const {
    return pais;
}

std::string Adega::getWeb() const {
    return web;
}

void Adega::adicionarVinho(const Vinho &v) {
    vinhos.emplace_back(v);
}

std::vector<Vinho> Adega::getVinhos() const {
    return vinhos;
}

std::ostream& operator<<(std::ostream& os, const Adega& adega) {
    os << "*** " << adega.nome << " ****\n";
    os << "Localidade: " << adega.localidade << "\n";
    os << "Pais: " << adega.pais << "\n";
    os << "Pagina Web: " << adega.web << "\n";
    os << "Lista de Vinhos:\n";
    for(auto & vinho: adega.vinhos) {
        os << vinho;
    }
    return os;
}
