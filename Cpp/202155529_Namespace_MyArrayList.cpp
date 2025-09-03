#include <iostream>

using namespace std;

namespace shape{
    class Shape{
    public:
        virtual void draw() const = 0;
        virtual bool isEqual(const Shape* const) const = 0;
        virtual Shape* clone() const = 0;
        virtual ~Shape() = default;
    };

    class Rectangle : public Shape {
        int x1, y1, x2, y2;
    public:
        Rectangle(int _x1, int _y1, int _x2, int _y2)
        : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
        }
        void draw() const{
            cout << "Rectangle: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")"<< '\n';
        }
        bool isEqual(const Shape* const r) const{
            const Rectangle* r_ptr = dynamic_cast<const Rectangle*>(r);
            if((r_ptr->x1==this->x1) && (r_ptr->y1==this->y1) &&
                (r_ptr->x2==this->x2)&& (r_ptr->y2==this->y2)) return true;
            else return false;
        }
        Shape* clone() const{
            Shape* r = new Rectangle(x1, y1, x2, y2);
            return r;
        }
    };

    class Circle : public Shape {
        int x, y;
        int radius;
    public:
        Circle(int _x, int _y, int _r)
        : x(_x), y(_y), radius(_r) {
        }
        void draw() const{
            cout << "Circle: (" << x << ", " << y << "), " << radius << '\n';
        }
        bool isEqual(const Shape* const c) const{
            const Circle* c_ptr = dynamic_cast<const Circle*>(c);
            if((c_ptr->x==this->x)&&(c_ptr->y==this->y)&&(c_ptr->radius==this->radius)) return true;
            else return false;
        }
        Shape* clone() const{
            Shape* c = new Circle(x, y, radius);
            return c;
        }
    };
}

namespace mystl{
    template <typename T, int size>
    class MyArrayList{
        T* data[size];
    public:
        MyArrayList(){
            for(int i = 0; i<size; i++){
                data[i] = nullptr;
            }
        }
        bool addElement(T* obj){
            for(int i = 0; i<size; i++){
                if(data[i]==nullptr){
                    data[i] = obj->clone();
                    return true;
                }
            }
            return false;
        }

        bool removeElement(T* obj){
            for(int i = 0; i < size; i++){ 
                if(data[i]!=nullptr && obj->isEqual(data[i])){ 
                    data[i] = nullptr;
                    return true;
                }
            }
            return false;
        }



        int getSize(void){ return size; }

        T* operator[](int index) {
            if (index >= 0 && index < size) {
                return data[index];
            }
            return nullptr;  // Index out of range, return nullptr
        }

        const T* operator[](int index) const {
            if (index >= 0 && index < size) {
                return data[index];
            }
            return nullptr;  // Index out of range, return nullptr
        }
    };
}

int main() {
	shape::Shape* r1 = new shape::Rectangle(0, 0, 10, 10);
	shape::Shape* r2 = new shape::Rectangle(0, 0, 20, 20);

	shape::Shape* c1 = new shape::Circle(0, 0, 10);
	shape::Shape* c2 = new shape::Circle(10, 10, 20);

	mystl::MyArrayList<shape::Shape, 5> list{};
	cout << boolalpha;
	cout << list.addElement(r1) << endl;
	cout << list.addElement(c1) << endl;
	delete c1;

	for (int i = 0; i < list.getSize(); i++) {
		shape::Shape* s = list[i];
		if (s == nullptr) continue;
		s->draw();
	}
	cout << list.removeElement(r1) << endl;
	shape::Circle temp(0, 0, 5);
	cout << list.removeElement(&temp) << endl;
	cout << list.addElement(c2) << endl;
	cout << list.addElement(r2) << endl;
	for (int i = 0; i < list.getSize(); i++) {
		shape::Shape* s = list[i];
		if (s == nullptr) continue;
		s->draw();
	}
}
