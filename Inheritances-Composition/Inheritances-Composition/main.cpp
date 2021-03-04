

#include <iostream>
using namespace std;
class Persona{
public:
    Persona(){}
    Persona(string _nombre, int _edad):
        nombre{_nombre}
    {
        if(edad < 0) throw string{"capullo"};
        edad = _edad;
    }
    int getEdad()const;
    void setEdad(const int &value);
        
    string getNombre()const;
    void setNombre(const string &value);
    
protected:
    string nombre;
    int edad;
};
class Alumno: public Persona{
private:
    int edadInicioCarrera;
public:
    Alumno(){};
    Alumno(string _nombre, int _edad):
    Persona{_nombre, _edad},
    edadInicioCarrera{18}
    {}
    int getAnoCarrera() const{
        return(edad - edadInicioCarrera);
    }
    int getEdadInicioCarrera() const;
    void setEdadInicioCarrera();
};

class Profesor: public Persona{
private:
    
    
};

int main(int argc, const char * argv[]) {
    Profesor yo;
    Alumno manolo;
    manolo.setNombre("Manolo");
    manolo.setEdad(19);
    yo.setNombre("ALberto");
    yo.setEdad(41);
    
    cout << "Hello " << yo.getNombre() << endl;
    cout << "Manolo empezó con " << manolo.getEdadInicioCarrera() << endl;
    
    return 0;
}
