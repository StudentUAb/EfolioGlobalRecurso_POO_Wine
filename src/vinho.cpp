#include "vinho.h"
#include <iostream>

Vinho::Vinho(const std::string &nome, const std::string &tipo, const std::vector<std::string> &castas, const std::vector<std::string> &refeicoes, double volAlcool) 
    : nome(nome), tipo(tipo), castas(castas), refeicoes(refeicoes), volAlcool(volAlcool) {}

std::string Vinho::getNome() const {
    return nome;
}

std::string Vinho::getTipo() const {
    return tipo;
}

std::vector<std::string> Vinho::getCastas() const {
    return castas;
}

std::vector<std::string> Vinho::getRefeicoes() const {
    return refeicoes;
}

double Vinho::getVolAlcool() const {
    return volAlcool;
}

std::ostream& operator<<(std::ostream& os, const Vinho& vinho) {
    os << "Nome: " << vinho.nome << "\n";
    os << "Tipo: " << vinho.tipo << "\n";
    os << "Volume: " << vinho.volAlcool << "\n";
    os << "Castas: ";
    for(auto & casta: vinho.castas) {
        os << casta << " ";
    }
    os << "\nTipo de Refeição: ";
    for(auto & refeicao: vinho.refeicoes) {
        os << refeicao << " ";
    }
    os << "\n\n";
    return os;
}
