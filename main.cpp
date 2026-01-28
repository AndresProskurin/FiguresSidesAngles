#include <iostream>

class Shape {

    protected:
        int sideCnt{0};
    public:
        Shape() {}
        int sideCount() {
            return sideCnt;
        }
        
        virtual void printInfo() {}
    };


class Triangle : public Shape {

    private:
        int a{};
        int b{};
        int c{};    
        int A{};
        int B{};
        int C{};

    public:
        Triangle(int a, int b, int c, int A, int B, int C) : Shape() {
            sideCnt = 3;
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        }
    
    public:
        int get_a() {
            return a;
        }
        int get_b() {
            return b;
        }
        int get_c() {
            return c;
        }
        int get_A() {
            return A;
        }
        int get_B() {
            return B;
        }
        int get_C() {
            return C;
        }

        void printInfo() override{
            std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << std::endl;
            std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << std::endl;
        }

};

class Quadrangle : public Shape {

    private:
        int a{};
        int b{};
        int c{};
        int d{};    
        int A{};
        int B{};
        int C{};
        int D{};

    public:
        Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Shape() {
            sideCnt = 4;
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
    
    public:
        int get_a() {
            return a;
        }
        int get_b() {
            return b;
        }
        int get_c() {
            return c;
        }
        int get_d() {
            return d;
        }
        int get_A() {
            return A;
        }
        int get_B() {
            return B;
        }
        int get_C() {
            return C;
        }
        int get_D() {
            return D;
        }

        void printInfo() override{
            std::cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
            std::cout << "Углы: A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << std::endl;
        }
};

class RightTriangle : public Triangle {
    public:
        RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {}
};

class IsoscelesTriangle : public Triangle {
    public:
        IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {}
};

class EquilateralTriangle : public Triangle {
    public:
        EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {}
};

class Parallelogram : public Quadrangle {
    public:
        Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {}
};
class Rectangle : public Parallelogram {
    public:
        Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {}
};


class Rhombus : public Parallelogram {
    public:
        Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {}
};

class Square : public Rhombus {
    public:
        Square(int a) : Rhombus(a, 90, 90) {}
};

void printInfo(Shape* s) {
    s->printInfo();
}
int main() {
    
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rectangle rectangle(10, 20);
    Rhombus rhombus(30, 30, 40);
    Square square(20);

    std::cout << "Треугольник:" << std::endl;
    printInfo(&triangle);
    std::cout << std::endl;
    std::cout << "Прямой треугольник:" << std::endl;
    printInfo(&rightTriangle);
    std::cout << std::endl;
    std::cout << "Равнобедренный треугольник:" << std::endl;
    printInfo(&isoscelesTriangle);
    std::cout << std::endl;
    std::cout << "Равносторонний треугольник:" << std::endl;
    printInfo(&equilateralTriangle);
    std::cout << std::endl;
    std::cout << "Четырехугольник:" << std::endl;
    printInfo(&quadrangle);
    std::cout << std::endl;
    std::cout << "Прямоугольник:" << std::endl;
    printInfo(&rectangle);
    std::cout << std::endl;
    std::cout << "Квадрат:" << std::endl;
    printInfo(&square);
    std::cout << std::endl;
    std::cout << "Параллелограмм:" << std::endl;
    printInfo(&parallelogram);
    std::cout << std::endl;
    std::cout << "Ромб:" << std::endl;
    printInfo(&rhombus);
    

    return 0;
}
