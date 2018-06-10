#include <iostream>
using namespace std;

namespace space0 {

class Regions_and_Capital { //области и столица
public:
string name;
string contr;
Regions_and_Capital() {
name = "Regions_and_Capital";
contr = "Districts_and_Cities_of_regional_submission.\n";
}
virtual void comment() {
cout << "На первом уровне находятся: " << endl;
cout << " *столица Беларуси - Минск," << endl;
cout << " *6 областей (Минская, Гомельская, Гродненская, Брестская, Витебская, Могилёвская)\n";
}
void rule() {
cout << name << " включают " << contr;
}
private:
protected:
};

class Districts_and_Cities_of_regional_submission : public virtual Regions_and_Capital { //районы и города областного подчинения
public:
Districts_and_Cities_of_regional_submission() {
name = "Districts_and_Cities_of_regional_submission";
contr = "Cities_of_district_submission.\n";
}

virtual void comment() {
cout << "На втором уровне находятся: " << endl;
cout << " *города областного подчинения с численностью населения не менее 50 тыс. чел., являющиеся административными и крупными экономическими и культурными центрами, с развитой производственной и социальной инфраструктурой," << endl;
cout << " *города с меньшим населением, но имеющие важное промышленное, историческое значение, перспективы дальнейшего развития и роста численности населения\n";
}
private:
protected:

};

class Cities_of_district_submission : public virtual Regions_and_Capital { //города районного подчинения
public:
Cities_of_district_submission() {
name = "Cities_of_district_submission";
contr = "Settlements_urban.\n";
}

virtual void comment() {
cout << "На третьем уровне находятся: " << endl;
cout << " *города районного подчинения с численностью населения более 6 тыс.чел., имеющие промышленные предприятия, сеть учреждений социально-культурного и бытового назначения, с перспективами дальнейшего развития\n";
}
private:
protected:

};

class Settlements_urban : public Cities_of_district_submission, public Districts_and_Cities_of_regional_submission{ //посёлки городского типа
public:
Settlements_urban() {
name = "Settlements_urban";
contr = "Rural_councils.\n";
}

virtual void comment() {
cout << "На четвёртом уровне находятся: " << endl;
cout << " *городские посёлки с численностью населения более 2 тыс.чел., имеющие промышленные и коммунальные предприятия, социально-культурные учреждения, предприятия торговли, общественного питания, бытового обслуживания," << endl;
cout << " *курортные посёлки с численностью населения более 2 тыс.чел., на территории которых расположены оздоровительные учреждения, предприятия торговли, общественного питания и бытового обслуживания населения, культурно-просветительные учреждения," << endl;
cout << " *рабочие посёлки с численностью населения более 500 чел., расположенные при промышленных предприятиях, электростанциях, стройках, железнодорожных станциях\n";
}
private:
protected:

};

class Rural_councils : protected Settlements_urban { //сельсоветы
public:
Rural_councils() {
name = "Rural_councils";
contr = "Rural_settlements.\n";
}

void check_protect() {
rule();
}

virtual void comment() {
cout << "На пятом уровне находятся:" << endl;
cout << " *сельсоветы, объединяющие несколько сельских населённых пунктов и входящие в состав районов\n";
}
private:
protected:

};

class Rural_settlements : private Rural_councils { //сельские населённые пункты
public:
Rural_settlements() {
name = "Rural_settlements";
contr = "ничего.\n";
}

void check_private() {
rule();
}

virtual void comment() {
cout << "На шестом уровне находятся: " << endl;
cout << " *агрогородки - благоустроенные населённые пункты, в которых создана производственная и социальная инфраструктура для обеспечения социальных стандартов проживающему в них населению и жителям прилегающих территорий," << endl;
cout << " *посёлки, деревни, хутора\n";
}
private:
protected:

};
}

using namespace space0;
Regions_and_Capital level1;
Districts_and_Cities_of_regional_submission level2;
Cities_of_district_submission level3;
Settlements_urban level4;
Rural_councils level5;
Rural_settlements level6;

int main()
{
    cout << "----------Административно-территориальное деление и населённые пункты----------\n";
level1.comment();
level1.rule();
level2.comment();
level2.rule();
level3.comment();
level3.rule();
level4.comment();
level4.rule();
level5.comment();
level5.check_protect();
level6.comment();
level6.check_private();

return 0;
}
