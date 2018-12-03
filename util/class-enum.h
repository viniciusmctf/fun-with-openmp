enum ElementType {
    Double, Single, Integer
};

enum ElementScale {
    Small, Medium, Big
};

enum ElementDistribution {
    Uniform, Normal, Beta, Alpha, T
};

enum ElementState {
    Running, Idle, Waiting, Starting, Ending
};

enum DataType {
    Array, Matrix, Cube, Hypercube, Dictionary
};

struct ConcreteData {
    DataType type;
    void * data;
};

class Element {
 public:
    Element(ElementType type = ElementType::Single,
            ElementScale scale = ElementScale::Medium,
            ElementDistribution dist = ElementDistribution::Uniform) :
                type(type), scale(scale), dist(dist),
                state(ElementState::Starting) {};
    ~Element();
    virtual void start();
    virtual void start_idle();
    virtual void run();
    Element* clone();
    virtual void * compute();

 protected:
    ElementType type;
    ElementScale scale;
    ElementDistribution dist;
    ElementState state;
    ConcreteData data;
    const ConcreteData& generate_distribution(DataType);

};
