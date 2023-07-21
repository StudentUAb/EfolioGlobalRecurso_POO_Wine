#ifndef ADEGA_H
#define ADEGA_H

#include <vector>
#include "vinho.h"

class Adega {
public:
    Adega(const std::string &nome, const std::string &localidade, const std::string &pais, const std::string &web);
    std::string getNome() const;
    std::string getLocalidade() const;
    std::string getPais() const;
    std::string getWeb() const;
    void adicionarVinho(const Vinho &v);
    std::vector<Vinho> getVinhos() const;

    friend std::ostream& operator<<(std::ostream& os, const Adega& adega);

private:
    std::string nome;
    std::string localidade;
    std::string pais;
    std::string web;
    std::vector<Vinho> vinhos;
};

#endif // ADEGA_H
