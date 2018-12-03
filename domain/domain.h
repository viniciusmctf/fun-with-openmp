/**
 * This is a synthetic benchmark, generating fork-join applications using the
 * open-mp tasks system.
 ***/
#pragma once

#include "class-enum.h"
#include "jacobi-computable.h"

class DomainElement : public Element {
 public:
    DomainElement(ElementType t, ElementScale s, ElementDistribution d) :
        Element(t,s,d) {};
    DomainElement() : Element() {};
    ~DomainElement();
    void start();
    void start_idle();
    void run();
    DomainElement* clone();
    void * compute();
 private:


};
