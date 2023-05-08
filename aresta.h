#ifndef ARESTA_H
#define ARESTA_H

class Aresta {
    public:
        Aresta (int v1, int v2, int peso): m_v1(v1), m_v2(v2), m_peso(peso) {}

        int getV1() { return m_v1; }
        int getV2() { return m_v2; }
        int getPeso() { return m_peso; }

        void setV1(int val) { m_v1 = val; }
        void setV2(int val) { m_v2 = val; }
        void setPeso(int val) { m_peso = val; }
        
    private:
        int m_v1, m_v2, m_peso;
};

#endif