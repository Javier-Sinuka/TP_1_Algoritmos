#include "VarList.h"

VarList::VarList() { head = nullptr; }

Variable* VarList::get_head() { return head; }

void VarList::add_variable(string Name, string Type, int IntValue) { // agrega correctamente


    Variable* NewVariable = new Variable(Name, Type, IntValue, nullptr);

    if (head == nullptr) {
        head = NewVariable;
    }
    else {
        NewVariable->set_Next(head);
        head = NewVariable;
    }

}
void VarList::add_variable(string Name, string Type, bool BoolValue) {

    Variable* NewVariable = new Variable(Name, Type, BoolValue, NULL);

    if (head == NULL) {
        head = NewVariable;
    }
    else {
        NewVariable->set_Next(head);
        head = NewVariable;
    }

}

void VarList::print(Variable* HeadOfList) {

    if (HeadOfList == NULL) { cout << "Final de la lista" << endl; return; }

    cout << HeadOfList->get_IntValue() << endl;
    cout << HeadOfList->get_BoolValue() << endl;

    print(HeadOfList->get_Next());
}