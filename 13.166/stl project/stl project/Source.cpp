#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

enum class contactGrps { Friends, Family, Coworker, Acquaintance };
class contact {
	std::string m_fN;
	std::string m_lN;
	int m_pPhNum;
	int m_sPhNum;
	std::string m_eMail;
	std::string m_addrs;
	std::string m_comp;
	contactGrps m_group;
public:
	contact(
		std::string fN,
		std::string lN,
		int pPhNum,
		int sPhNum,
		std::string eMail,
		std::string addrs,
		std::string comp,
		contactGrps group) :m_fN(fN), m_lN(lN),
		m_pPhNum(pPhNum), m_sPhNum(sPhNum),
		m_eMail(eMail), m_addrs(addrs),
		m_comp(comp), m_group(group) {};

	const std::string& get_fN() const { return m_fN; };
	const std::string& get_lN() const { return m_lN; };
	const int& get_pPhNum() const { return m_pPhNum; };
	const int& get_sPhNum() const { return m_sPhNum; };
	const std::string& get_eMail() const { return m_eMail; };
	const std::string& get_addrs() const { return m_addrs; };
	const std::string& get_comp() const { return m_comp; };
	contactGrps get_conGrp() const { return m_group; };
	bool operator < (const contact& c) const {
		return m_fN < c.m_fN;
	}
};
std::vector<contact> createContactBook() {
	std::vector<contact> cb{
		contact{"Amir","Hadi",8010,8304,"amirhossein.hadi@gmail.com","A6-1870 West 6th Avenue","UBC",contactGrps::Friends},
		contact{"Reza","Nich",9010,1031,"reza.nickmanesh@gmail.com","903-899 West Georgia","PHC",contactGrps::Friends},
		contact{"Moh","Amini",5482,6987,"mohammad.amini@gmail.com","2010-989 Expo Blvd","FOOTSM", contactGrps::Friends},
		contact{"Maryam", "Eslami",4568,4785,"maryam.eslami@yahoo.com","1503-148 Ash st","EYECARE", contactGrps::Family},
		contact{"Sina","Amini",4521,9685,"sina.amininiaki@gmail.com","3101-2204 Beatty st", "UBC",contactGrps::Acquaintance},
		contact{"Hajr","Adl", 1223,8455,"hajir.adl@ubc.ca","2234-543 Marine Drive", "PHC", contactGrps::Coworker}
	};
	return cb;
}

int main() {
	std::string sortType{ "LN" };
	std::vector<contact> v = createContactBook();
	if (sortType == "LN")
		std::sort(v.begin(), v.end(), [](const contact& c1, const contact& c2) {return (c1.get_lN() < c2.get_lN()); });

	std::for_each(v.begin(), v.end(), [](const contact& c) {
		std::cout << c.get_fN() << ", " << c.get_lN() <<
			": pPhn: " << c.get_pPhNum() <<
			", sPhn: " << c.get_sPhNum() <<
			", eMail: " << c.get_eMail() <<
			", Addrs: " << c.get_addrs() <<
			", comp: " << c.get_comp() <<
			": group: " << (int)c.get_conGrp() <<
			std::endl; });

	std::cout << std::endl;

	std:for_each(v.begin(), v.end(), [](const auto& c) {std::cout << c.get_fN() << ": " << c.get_pPhNum() << std::endl; });
	
	std::cout << std::endl;
	
	std::string company{"UBC"};
	std::for_each(v.begin(), v.end(), [company](const auto& c) {
		if (c.get_comp() == company)
			std::cout << c.get_fN() << ", " << c.get_lN() <<
			": pPhn: " << c.get_pPhNum() <<
			", sPhn: " << c.get_sPhNum() <<
			", eMail: " << c.get_eMail() <<
			", Addrs: " << c.get_addrs() <<
			", comp: " << c.get_comp() <<
			": group: " << (int)c.get_conGrp() <<
			std::endl; });

	std::cout << std::endl;
	contactGrps group{contactGrps::Friends};
	std::for_each(v.begin(), v.end(), [group](const auto& c) {
		if (c.get_conGrp() == group)
			std::cout << c.get_fN() << ", " << c.get_lN() <<
			": pPhn: " << c.get_pPhNum() <<
			", sPhn: " << c.get_sPhNum() <<
			", eMail: " << c.get_eMail() <<
			", Addrs: " << c.get_addrs() <<
			", comp: " << c.get_comp() <<
			": group: " << (int)c.get_conGrp() <<
			std::endl; });


	return 0;
}