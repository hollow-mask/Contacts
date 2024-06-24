#include <iostream>
#include <string>

#include "p3.h"

using namespace std;

Info::Info() {
    this->name = "No Name Set";
    this->value = "No Value Set";
    this->next = nullptr;
}

Info::Info(std::string name, std::string value, Info *next) {
    this->name = name;
    this->value = value;
    this->next = next;
}

Contact::Contact() {
    this->first = "No First Set";
    this->last = "No Last Set";
    this->next = nullptr;
    this->headInfoList = nullptr;
}

Contact::Contact(std::string first, std::string last, Contact *next) {
    this->first = first;
    this->last = last;
    this->next = next;
    this->headInfoList = nullptr;
}

ContactList::ContactList() {
    this->headContactList = nullptr;
    this->count = 0;
}

int ContactList::getCount() {
    return this->count;
}

// print the specified contact and its information
// 1. return false and print nothing if the contact is not in the list
// 2. otherwise return true and print the contact
bool ContactList::printContact(std::ostream &os, std::string first, std::string last) {
    // Contact* s = headContactList;
    if(headContactList == nullptr){
        return false;
    }
     Contact* s = headContactList;
    //while(s->next != nullptr){
    for(s = headContactList; s!=nullptr; s= s->next){
        if(s->first == first && s->last == last){
            break;
        }
        //s = s->next;
        if(s->next == nullptr){
            return false;
        }
    }

    os<<"Contact Name: "<< s->first<<" "<<s->last<<endl;

    if (s->headInfoList != nullptr){
    Info* i = s->headInfoList;
    //while(i->next != nullptr){
        for(i = s->headInfoList; i != nullptr; i=i->next){
            os<< "\t"<<i->name<<" | "<<i->value<<endl;
            //i = i->next;
        } 
    } 
    return true;
}

// print all contacts and their information
// print nothing if the list is empty
void ContactList::print(std::ostream &os) {
    
    //  Contact* s = headContactList;
    //  Info* i = s->headInfoList;
    //while(s->next != nullptr){
    if(headContactList != nullptr){
      Contact* s = headContactList;
     Info* i = s->headInfoList;  
        
    for(s=headContactList;s!=nullptr; s=s->next){
       os<<"Contact Name: "<< s->first<<" "<<s->last<<endl;

        //while(i->next != nullptr){
            if(s->headInfoList != nullptr){
                for(i=s->headInfoList;i!=nullptr; i=i->next){
                    os<< "\t"<<i->name<<" | "<<i->value<<endl;
            //i = i->next;
                }
        }  
    //s = s->next;
    }
    }


}

// add a contact to the back of the list
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the back of the list
// - do not forget to update count
bool ContactList::addContact(std::string first, std::string last) {
   //
   // count++;
    Contact* n = new Contact(first, last);
    if(headContactList == nullptr){
        headContactList = n;
        ///cout<<"***"<<endl;
        count++;
        return true;
    }

    Contact* lastc = headContactList;
    //while(lastc->next != nullptr){
        for(lastc = headContactList; lastc!=nullptr; lastc=lastc->next){
        if(lastc->first == first && lastc->last == last){
            delete n;
            return false;
        }

        if(lastc->next == nullptr){
            break;
        }
        //lastc = lastc->next;
        
    }
    //cout<<"HI"<<endl;
    lastc->next = n;
    count++;
    return true;
}

// add info to the back of a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the back of the contact's list and return true
bool ContactList::addInfo(std::string first, std::string last, std::string infoName, std::string infoVal) {
    Contact* s = headContactList;
    //while(s->next != nullptr){
        for(s=headContactList;s!=nullptr;s=s->next){

        if(s->first == first && s->last == last){
            //cout<<"found you"<<s->first<<" "<<s->last<<endl;
            break;
        }
        //s = s->next;
        if(s->next == nullptr){
            return false;
        }
    }
    Info* n = new Info(infoName, infoVal);

    if(s->headInfoList == nullptr){
        s->headInfoList = n;
        //cout<<"not empty anymore"<<endl;
       
        return true;
    }

    Info* lastc = s->headInfoList;
    //cout<<"checking: "<<s->first<<" "<<s->last<<endl;
    //while(lastc->next!= nullptr){
        for(lastc=s->headInfoList;lastc!=nullptr;lastc=lastc->next){
        if(lastc->name == infoName){
            lastc->value = infoVal;

            return true;
        }

        if(lastc->next == nullptr){
            break;
        }
        //lastc = lastc->next;
    }

    lastc->next = n;
    return true;
}

// add a contact to the list in ascending order by last name
//     if last names are equal, then order by first name ascending
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the list
// - do not forget to update count
// - compare strings with the built-in comparison operators: <, >, ==, etc.
// - a compare method/function is recommended
bool ContactList::addContactOrdered(std::string first, std::string last) {

        


        // Contact * c= headContactList;
        // cout<<"IM HEAR"<<endl;
        // int r= 0;

        

        // while(c->next != nullptr){
        //     cout<<r<<endl;
        //     r++;
        //     if(c->first == first && c->last == last){
        //         return false;
        //     }
        // }

        Contact * n = new Contact(first, last);
        n->next = nullptr;
        if(headContactList == nullptr){
            //cout<<"IBIJinn"<<endl;
            headContactList = n;
            count++;
            return true;
        }

        //Contact * c= headContactList;
        //cout<<"IM HEAR"<<endl;
        //int r= 0;

        
         for (Contact *cur = headContactList; cur != nullptr; cur = cur->next) {
            if (cur->first == first && cur->last == last){
                delete n;
                return false;
            }

         }
        

         if( n->last < headContactList->last){
            n->next = headContactList;
            headContactList = n;
            count++;
            return true;
        }

        else if(n->first < headContactList->first && n->last == headContactList->last){
            n->next = headContactList;
            headContactList = n;
            count++;
            return true;
        }


        else{
            Contact* prev = headContactList;
            Contact* cur = headContactList->next;
            //while(cur != nullptr){
                for(cur = headContactList->next;cur!=nullptr;cur = cur->next){
                if( n->last < cur->last){
                    break;
                }
                else if(n->first < cur->first && n->last == cur->last){
                    break;
                }
                prev = prev->next;
                //cur = cur->next;
            }

            prev->next = n;
            n->next = cur;
        }
        count++;

    return true;
}

// add info to a contact's info list in ascending order by infoName
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the contact's list and return true
bool ContactList::addInfoOrdered(std::string first, std::string last, std::string infoName, std::string infoVal) {


     Contact * s = headContactList;
        
        //cout<<"IM HEAR"<<endl;
        //int r= 0;

        
         for (s = headContactList; s != nullptr; s = s->next) {
            if (s->first == first && s->last == last){
                break;
            }
            if(s->next == nullptr){
                return false;
            }

         }
        //cout<<"WE MADE IT"<<endl;

    // Contact* s = headContactList;
    // while(s->next != nullptr){

    //     if(s->first == first && s->last == last){
    //         break;
    //     }
    //     s = s->next;
    //     if(s->next == nullptr){
    //         return false;
    //     }
    // }


    Info * n = new Info(infoName, infoVal);
        if(s->headInfoList == nullptr){
            s->headInfoList = n;
            //cout<<"^^^^"<<endl;
            return true;
            //cout<<"^^^^"<<endl;
        }

        else if( n->name < s->headInfoList->name){
            n->next = s->headInfoList;
            s->headInfoList = n;
            //cout<<"^^$$^^"<<endl;
            return true;
        }

        else if( n->name == s->headInfoList->name){
            //cout<<"^^&&&^^"<<endl;
             s->headInfoList->value = n->value ;
            return true;
        }

        else{
            Info* prev = s->headInfoList;
            Info* curr = s->headInfoList->next;
            //while(s != nullptr){
                for(curr=s->headInfoList->next;curr!=nullptr;curr=curr->next){
                //cout<<"HI LOOP"<<endl;
                if( n->name < curr->name){
                    break;
                }
                else if(n->name == curr->name){
                    n->value = curr->value;
                    return true;
                }
                prev = prev->next;
                //curr = curr->next;
            }
            //cout<<"^^$@@@^^"<<endl;

            prev->next = n;
            n->next = curr;
        }
    return true;
}

// remove the contact and its info from the list
// 1. return false and do nothing if the contact is not in the list
// 2. otherwise return true and remove the contact and its info
// - do not forget to update count
bool ContactList::removeContact(std::string first, std::string last) {

    Contact* cur = headContactList;
    Contact* prev = headContactList;
    //while(lastc->next != nullptr){
        for(cur = headContactList; cur!=nullptr; cur=cur->next){
        if(cur->first == first && cur->last == last){
            if(cur == headContactList){//delete head contact
                headContactList = cur->next;

            }
            else{//delete any other contact
                prev->next = cur->next;
            }

            Info* d = cur->headInfoList; 
            while(d != nullptr){
                Info* temp = d;
                d=d->next;
                delete temp;
            }

            delete cur;
            
            count--;
            return true;
        }

        if(cur->next == nullptr){
            return false;
        }
        prev = cur;
        
    }
    

    return true;
}

// remove the info from a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. return false and do nothing if the info is not in the contact's info list
// 3. otherwise return true and remove the info from the contact's list
bool ContactList::removeInfo(std::string first, std::string last, std::string infoName) {
    Contact* cur = headContactList;

    for(cur = headContactList; cur != nullptr; cur = cur->next){
        if(cur->first == first && cur->last == last){
            Info* d= cur->headInfoList;
            Info* prev = d;
            for(d=cur->headInfoList; d!=nullptr; d= d->next){
                if(d->name == infoName){
                    if(d == cur->headInfoList){
                        cur->headInfoList = d->next;
                    }
                    else{
                        prev->next = d->next;
                    }
                    delete d;
                    return true;
                }
                if(d->next == nullptr){
                    return false;
                }
                prev = d;
            }
        }

        if(cur->next == nullptr){
            return false;
        }
    }
    return true;
}

// destroy the list by removing all contacts and their infos
ContactList::~ContactList() {
    for(Contact*cur = headContactList; cur!=nullptr; cur = cur->next){
        removeContact(cur->first, cur->last);
    }

}

// deep copy the source list
// - do not forget to update count
ContactList::ContactList(const ContactList &src) {
    //cout<<"HIII"<<endl;
    count = src.count;
    Contact* cur = src.headContactList;
    for(cur = src.headContactList; cur !=nullptr; cur = cur->next){
        //cout<<"COPY LOOP"<<endl;
        addContact(cur->first,cur->last);
        for(Info* n = cur->headInfoList; n!=nullptr; n= n->next){
            addInfo(cur->first, cur->last, n->name, n->value);
        }
    }

}

// remove all contacts and their info then deep copy the source list
// - do not forget to update count
const ContactList &ContactList::operator=(const ContactList &src) {
    ContactList * list = nullptr;
    count = src.count;
    if (this != &src) {
        delete this;
        list =  new ContactList(src);

    }
    return *list;
}
