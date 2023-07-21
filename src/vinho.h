#ifndef VINHO_H
#define VINHO_H

#include <string>
#include <vector>

class Vinho {
public:
    Vinho(const std::string &nome, const std::string &tipo, const std::vector<std::string> &castas, const std::vector<std::string> &refeicoes, double volAlcool);
    std::string getNome() const;
    std::string getTipo() const;
    std::vector<std::string> getCastas() const;
    std::vector<std::string> getRefeicoes() const;
    double getVolAlcool() const;

    friend std::ostream& operator<<(std::ostream& os, const Vinho& vinho);


private:
    std::string nome;
    std::string tipo;
    std::vector<std::string> castas;
    std::vector<std::string> refeicoes;
    double volAlcool;
};

#endif // VINHO_H
