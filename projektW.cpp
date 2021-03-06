#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstring>

#include "trzoda_t.h"
#include "traktor_z.h"
#include "agregat_p.h"
#include "grunty_o.h"
#include "tucznik.h"
#include "zetor.h"
#include "podorywkowy.h"
#include "pole.h"

using namespace std;

class wytwornia_z
{
public:
	obsada* produkuj()
	{
		return zalazki.at(0) ->produkuj();
	}

	void rejestruj_zalazek(zalazek *zal)
	{
		zalazki.push_back(zal);
	}
	virtual ~wytwornia_z()
	{
		for(size_t i=0; i<zalazki.size(); ++i)
			delete zalazki.at(i);
		zalazki.clear();
	}
protected:
	vector<zalazek*> zalazki;
};

class wytwornia_ms
{
public:
	maszyna_s* zbuduj()
	{
		return producenci_s.at(0) ->zbuduj();
	}

	void rejestruj_producent_s(producent_s *producents)
	{
		producenci_s.push_back(producents);
	}
	virtual ~wytwornia_ms()
	{
		for(size_t i=0; i<producenci_s.size(); ++i)
			delete producenci_s.at(i);
		producenci_s.clear();
	}
protected:
	vector<producent_s*> producenci_s;
};

class wytwornia_mz
{
public:
	maszyna_z* zabuduj()
	{
		return producenci_z.at(0) ->zabuduj();
	}

	void rejestruj_producent_z(producent_z *producentz)
	{
		producenci_z.push_back(producentz);
	}
	virtual ~wytwornia_mz()
	{
		for(size_t i=0; i<producenci_z.size(); ++i)
			delete producenci_z.at(i);
		producenci_z.clear();
	}
protected:
	vector<producent_z*> producenci_z;
};

class wytwornia_g
{
public:
	ziemia* karczuj()
	{
		return grunt.at(0) ->karczuj();
	}

	void rejestruj_grunty(grunty *grun)
	{
		grunt.push_back(grun);
	}
	virtual ~wytwornia_g()
	{
		for(size_t i=0; i<grunt.size(); ++i)
			delete grunt.at(i);
		grunt.clear();
	}
protected:
	vector<grunty*> grunt;
};


int main()
{
	char klawisz1, klawisz2, klawisz3, klawisz4, klawisz5, klawisz6, rasa[20], plec[20], nazwa[20], funkcja[20], marka[20];
	int ile, e=0, e_s=0, e_z=0, e_g=0;
	float wiek=0, masa=0, bank=0;
	srand(unsigned(time(NULL)));
	wytwornia_z z;
	wytwornia_ms ms;
	wytwornia_mz mz;
	wytwornia_g g;

	z.rejestruj_zalazek(new trzoda_t());
	
	ms.rejestruj_producent_s(new traktor_z());
	mz.rejestruj_producent_z(new agregat_p());

	g.rejestruj_grunty(new grunty_o());

	
	vector<obsada*> chlew;
	vector<maszyna_s*> garaz;
	vector<maszyna_z*> wiata;
	vector<ziemia*> grunt;
//-----------------------------------------------------------------------------
	

	do
	{
		system("cls");
		cout<<"pracuj ze zwierzetami --> 1"<<endl<<"pracuj z maszynami samojezdnymi --> 2"<<endl<<"pracuj z pozosta�ymi maszynami --> 3"<<endl<<"pracuj w polu --> 4"<<endl<<"stan gospodarstwa -->5"<<endl<<"wyjscie --> Q"<<endl;
		cin>>klawisz1;
		switch(klawisz1)
		{
		case '1':
				system("cls");
				cout<<"kup --> 1"<<endl<<"sprzedaj --> 2"<<endl<<"nakarm --> 3"<<endl;
				cin>>klawisz2;
				switch(klawisz2)
				{
					case '1':
							system("cls");
							ile=0;
							cout<<"Ile zwierz�t chcesz kupi� chcesz kupi�"<<endl;
							cin>>ile;
							cout<<"Podaj nazwe zwierz�cia"<<endl;
							cin>>nazwa;
							cout<<"Podaj rase zwierz�cia"<<endl;
							cin>>rasa;
							cout<<"Podaj plec [XY/ XX] zwierz�cia"<<endl;
							cin>>plec;
							cout<<"Podaj wiek [mies.] zwierz�cia"<<endl;
							cin>>wiek;
							cout<<"Podaj masa [kg] zwierz�cia"<<endl;
							cin>>masa;
							if(_stricmp(nazwa, "tucznik")==0)
								bank=bank-ile*masa*float(8);
							else if(_stricmp(nazwa, "byk")==0)
								bank=bank-ile*masa*float(10);
							else if(_stricmp(nazwa, "maciora")==0)
								bank=bank-ile*masa*float(8);
							else
								bank=bank-ile*masa*float(10);
							for(size_t i=0; i<unsigned(ile); ++i)
							{
								chlew.push_back(z.produkuj());
								obsada* szt=chlew.at(e);
								strcpy(szt->nazwa, nazwa);
								strcpy(szt->rasa, rasa);
								strcpy(szt->plec, plec);
								szt->wiek=wiek;
								szt->masa=masa;
								e++;
							}
							
							cout<<"Zwierzeta zostaly kupione"<<endl;
							system("pause");
							break;
					case '2':
							system("cls");							
							cout<<"podaj nazwe zwierzecia kt�re chcesz sprzedac"<<endl;
							cin>>nazwa;
							for(size_t i=0; i<chlew.size(); ++i)
							{
								obsada* szt=chlew.at(i);
								cout<<szt->nazwa;
								if(_stricmp(szt->nazwa, nazwa)==0)
								{
									if(_stricmp(nazwa, "tucznik")==0 || _stricmp(nazwa, "maciora")==0)
									{
										if(szt->masa >= 100)
										{
											delete chlew.at(i);
											bank=bank+szt->masa*float(8);
										}
									}
									else if(_stricmp(nazwa, "byk")==0)
									{
										if(szt->wiek >=24 )
										{
											delete chlew.at(i);
											bank=bank+szt->masa*float(10);
										}
									}
									else 
									{
											delete chlew.at(i);
											bank=bank+szt->masa*float(10);								
									}
								}
							}
							cout<<"Zwierzeta zostaly sprzedane"<<endl;
							system("pause");
							break;
					case '3':
							for(size_t i=0; i<chlew.size(); ++i)
							{
								obsada* szt=chlew.at(i);
								szt->stan=0;
								if(_stricmp(nazwa, "tucznik")==0)
								{
									szt->masa=szt->masa+float(0.4);
									bank=bank-float(0.6);
								}
								else if(_stricmp(nazwa, "maciora")==0)
								{
									szt->masa=szt->masa+float(0.1);
									bank=bank-float(0.2);
								}
								else if(_stricmp(nazwa, "byk")==0)
								{
									szt->masa=szt->masa+float(0.6);
									bank=bank-float(0.8);
								}
								else
								{
									szt->masa=szt->masa+float(0.6);
									bank=bank-float(0.8);
								}
							}
							cout<<"Zwierzeta zostaly nakarmione"<<endl;
							system("pause");
							break;
					default:
							break;
				}
			
				break;
		case '2':
				system("cls");
				cout<<" kup --> 1"<<endl<<"sprzedaj -- >2"<<endl<<"napraw --> 3"<<endl<<""<<endl;
				cin>>klawisz3;
				switch(klawisz3)
				{
						case '1':
								system("cls");
								cout<<"Podaj nazwe maszyny jak� chcesz kupic"<<endl;
								cin>>nazwa;
								ile=0;
								cout<<"Ile maszyn samojezdnych chcesz kupi�"<<endl;
								cin>>ile;
								cout<<"Podaj marke maszyny"<<endl;
								cin>>marka;
								cout<<"Podaj model maszyny"<<endl;
								cin>>rasa;
								cout<<"Podaj rocznik maszyny"<<endl;
								cin>>wiek;
								cout<<"Podaj moc maszyny"<<endl;
								cin>>masa;
								bank=bank-float(150000)*ile;
								for(size_t i=0; i<unsigned(ile); ++i)
								{
									garaz.push_back(ms.zbuduj());
									maszyna_s* szt=garaz.at(e_s);
									strcpy(szt->nazwa, nazwa);
									strcpy(szt->marka, marka);
									strcpy(szt->model, rasa);
									szt->rocznik=wiek;
									szt->moc=masa;
									e_s++;
								}
								cout<<"Maszyna zostala kupiona"<<endl;
								system("pause");
								break;
						case '2':
								system("cls");							
								cout<<"podaj nazwe maszyny samojezdnej kt�ra chcesz sprzedac"<<endl;
								cin>>nazwa;
								cout<<"podaj marke maszyny samojezdnej kt�ra chcesz sprzedac"<<endl;
								cin>>marka;
								cout<<"podaj model maszyny samojezdnej kt�ra chcesz sprzedac"<<endl;
								cin>>rasa;
								for(size_t i=0; i<garaz.size(); ++i)
								{
									maszyna_s* szt=garaz.at(i);
									if(_stricmp(szt->nazwa, nazwa)==0)
									{	
										if(_stricmp(szt->marka, marka)==0)
										{	
											if(_stricmp(szt->model, rasa)==0)
											{	
												delete garaz.at(i);
												bank=bank+float(60000);	
											}
											else
											{
												cout<<"Nie ma takiej maszyny"<<endl;
												break;
											}
										}
									}
								}
								cout<<"Maszyna zostala sprzedana"<<endl;
								system("pause");
								break;
						case '3':
								system("cls");							
								cout<<"podaj nazwe maszyny samojezdnej kt�ra chcesz naprawic"<<endl;
								cin>>nazwa;
								cout<<"podaj marke maszyny samojezdnej kt�ra chcesz naprawic"<<endl;
								cin>>marka;
								cout<<"podaj model maszyny samojezdnej kt�ra chcesz naprawic"<<endl;
								cin>>rasa;
								for(size_t i=0; i<garaz.size(); ++i)
								{
									maszyna_s* szt=garaz.at(i);
									if(_stricmp(szt->nazwa, nazwa)==0)
									{	
										if(_stricmp(szt->marka, marka)==0)
										{	
											if(_stricmp(szt->model, rasa)==0)
											{	
												szt->stan=0;
												bank=bank- rand() %10000;
											}
											else
											{
												cout<<"Nie ma takiej maszyny"<<endl;
												break;
											}
										}
									}
								}
								cout<<"Maszyna zostala naprawiona"<<endl;
								system("pause");
								break;
						default:
								break;
				}
				break;
		case '3':
				system("cls");
				cout<<" kup --> 1"<<endl<<"sprzedaj -->2"<<endl<<"napraw --> 3"<<endl;
				cin>>klawisz4;
				switch(klawisz4)
				{
						case '1':
								system("cls");
								ile=0;
								cout<<"Ile maszyn chcesz kupi�"<<endl;
								cin>>ile;
								cout<<"Podaj nazwe maszyny"<<endl;
								cin>>nazwa;
								cout<<"Podaj marke maszyny"<<endl;
								cin>>rasa;
								cout<<"Podaj model maszyny"<<endl;
								cin>>plec;
								cout<<"Podaj funkcje jak� ma pelnic maszyna"<<endl;
								cin>>funkcja;
								bank=bank-ile*float(60000);
								for(size_t i=0; i<unsigned(ile); ++i)
								{
									wiata.push_back(mz.zabuduj());
									maszyna_z* szt=wiata.at(e_z);
									strcpy(szt->nazwa, nazwa);
									strcpy(szt->marka, marka);
									strcpy(szt->model, rasa);
									strcpy(szt->funkcja,funkcja);
									e_z++;
								}
								cout<<"Maszyna zostala kupiona"<<endl;
								system("pause");
								break;
						case '2':
								system("cls");							
								cout<<"podaj nazwe maszyny kt�ra chcesz sprzedac"<<endl;
								cin>>nazwa;
								cout<<"podaj marke maszyny kt�ra chcesz sprzedac"<<endl;
								cin>>marka;
								cout<<"podaj model maszyny kt�ra chcesz sprzedac"<<endl;
								cin>>rasa;
								for(size_t i=0; i<wiata.size(); ++i)
								{
									maszyna_z* szt=wiata.at(i);
									if(_stricmp(szt->nazwa, nazwa)==0)
									{	
										if(_stricmp(szt->marka, marka)==0)
										{	
											if(_stricmp(szt->model, rasa)==0)
											{	
												delete wiata.at(i);
												bank=bank+float(25000);	
											}
											else
											{
												cout<<"Nie ma takiej maszyny"<<endl;
												break;
											}
										}
									}
								}
								cout<<"Maszyna zostala sprzedane"<<endl;
								system("pause");
								break;
						case '3':
								system("cls");							
								cout<<"podaj nazwe maszyny kt�ra chcesz naprawic"<<endl;
								cin>>nazwa;
								cout<<"podaj marke maszyny kt�ra chcesz naprawic"<<endl;
								cin>>marka;
								cout<<"podaj model maszyny kt�ra chcesz naprawic"<<endl;
								cin>>rasa;
								for(size_t i=0; i<wiata.size(); ++i)
								{
									maszyna_z* szt=wiata.at(i);
									if(_stricmp(szt->nazwa, nazwa)==0)
									{	
										if(_stricmp(szt->marka, marka)==0)
										{	
											if(_stricmp(szt->model, rasa)==0)
											{	
												szt->stan=0;
												bank=bank- rand() %1000;
											}
											else
											{
												cout<<"Nie ma takiej maszyny"<<endl;
												break;
											}
										}
									}
								}
								cout<<"Maszyna zostala naprawiona"<<endl;
								system("pause");
								break;
						default:
								break;
				}
				break;
		case '4':
				system("cls");
				cout<<" kup --> 1"<<endl<<"sprzedaj -->2"<<endl<<"uprawiaj --> 3"<<endl;
				cin>>klawisz5;
				switch(klawisz5)
				{
					case '1':
							system("cls");
							for(size_t i=0; i<1; ++i)
							{
							grunt.push_back(g.karczuj());
							ziemia* szt=grunt.at(e_g);
							cout<<"Ile hektarow na jednej dzialce chcesz kupi�"<<endl;
							cin>>szt->powierzchnia;
							cout<<"Podaj nr dzialki"<<endl;
							cin>>szt->nrdzialki;
							bank=bank-szt->powierzchnia*float(80000);
							szt->stan=0;
							strcpy(szt->uprawa, "ugor");
							cout<<"Pole zosta�o kupione"<<endl;
							}
							system("pause");
							break;
					case '2':
							system("cls");							
							cout<<"Podaj numer dzialki ktore chcesz sprzedac"<<endl;
							cin>>masa;
							for(size_t i=0; i<grunt.size(); ++i)
							{
								ziemia* szt=grunt.at(i);
								if(szt->nrdzialki==masa)
								{	
									bank=bank+szt->powierzchnia*float(80000);
									delete grunt.at(i);																				
								}
							}
							cout<<"Pole zosta�o sprzedane"<<endl;
							system("pause");		
							break;
					case '3':
							system("cls");							
							cout<<"podaj nr dzia�ki na ktorej chcesz pracowa�"<<endl;
							cin>>masa;
							for(size_t i=0; i<grunt.size(); ++i)
							{
								ziemia* szt=grunt.at(i);
								if(szt->nrdzialki==masa)
								{										
									do
									{
										system("cls");
										cout<<"oraj --> 1"<<endl<<"uprawiaj --> 2"<<endl<<"zasiej --> 3"<<endl<<"daj nawoz --> 4"<<endl<<"opryskaj -->5"<<endl<<"zbierz --> 6"<<endl<<"wyjscie --> Q"<<endl;
										cin>>klawisz6;
										switch(klawisz6)
										{
											case '1':
													if(szt->stan==6 || szt->stan==0)
													{
														system("cls");	
														cout<<"Podaj nazwe maszyny kt�rym chcesz orac"<<endl;
														cin>>nazwa;
														cout<<"Podaj marke maszyny kt�rym chcesz orac"<<endl;
														cin>>marka;
														cout<<"Podaj model maszyny kt�rym chcesz orac"<<endl;
														cin>>marka;
														for(size_t i=0; i<garaz.size(); ++i)
														{
															maszyna_s* szt1=garaz.at(i);
															if(_stricmp(szt1->nazwa, nazwa)==0)
															{
																if(_stricmp(szt1->marka, marka)==0)
																{	
																	if(_stricmp(szt1->model, rasa)==0)
																	{
																		if(rand() %100==10)
																		{
																			szt1->stan=1;
																			cout<<"Traktor sie popsu�"<<endl;
																			system("pause");
																			break;
																		}
																	}
																	else
																	{
																		cout<<"Nie ma takiej maszyny"<<endl;
																		break;
																	}
																}
															}
														}
														cout<<"podaj marke p�uga kt�rym chcesz orac"<<endl;
														cin>>nazwa;
														for(size_t i=0; i<wiata.size(); ++i)
														{
															maszyna_z* szt2=wiata.at(i);
															if(_stricmp(szt2->nazwa, "plug")==0)
															{	
																if(_stricmp(szt2->marka, nazwa)==0)
																{										
																	if(rand() %100==10)
																	{
																		szt2->stan=1;
																		cout<<"plug sie popsu�"<<endl;
																		system("pause");
																		break;
																	}
																}
																else
																{
																	cout<<"Nie ma takiej maszyny"<<endl;
																	break;
																}
															}
														}
														szt->stan=1;
														bank=bank-szt->powierzchnia*float(11)*float(4.5);
														cout<<"zaorano"<<endl;
													}
													break;
											case '2':
													if(szt->stan==1 || szt->stan==6 || szt->stan==4)
													{
														system("cls");	
														cout<<"Podaj nazwe maszyny kt�rym chcesz uprawia�"<<endl;
														cin>>nazwa;
														cout<<"Podaj marke maszyny kt�rym chcesz uprawia�"<<endl;
														cin>>marka;
														cout<<"Podaj model maszyny kt�rym chcesz uprawia�"<<endl;
														cin>>marka;
														for(size_t i=0; i<garaz.size(); ++i)
														{
															maszyna_s* szt1=garaz.at(i);
															if(_stricmp(szt1->nazwa, nazwa)==0)
															{
																if(_stricmp(szt1->marka, marka)==0)
																{	
																	if(_stricmp(szt1->model, rasa)==0)
																	{
																		if(rand() %100==10)
																		{
																			szt1->stan=1;
																			cout<<"Traktor sie popsu�"<<endl;
																			system("pause");
																			break;
																		}
																	}
																	else
																	{
																		cout<<"Nie ma takiej maszyny"<<endl;
																		break;
																	}
																}
															}
														}
														cout<<"podaj marke agreagtu kt�rym chcesz uprawia�"<<endl;
														cin>>nazwa;
														for(size_t i=0; i<wiata.size(); ++i)
														{
															maszyna_z* szt2=wiata.at(i);
															if(_stricmp(szt2->nazwa, "agregat")==0)
															{	
																if(_stricmp(szt2->marka, nazwa)==0)
																{										
																	if(rand() %100==10)
																	{
																		szt2->stan=1;
																		cout<<"agregat sie popsu�"<<endl;
																		system("pause");
																		break;
																	}
																}
																else
																{
																	cout<<"Nie ma takiej maszyny"<<endl;
																	break;
																}
															}
														}
														szt->stan=2;
														bank=bank-szt->powierzchnia*float(9)*float(4.5);
														cout<<"uprawiono"<<endl;
													}
													break;
											case '3':
													if(szt->stan==1 || szt->stan==2 || szt->stan==4)
													{
														system("cls");	
														cout<<"Podaj nazwe maszyny kt�rym chcesz siac"<<endl;
														cin>>nazwa;
														cout<<"Podaj marke maszyny kt�rym chcesz siac"<<endl;
														cin>>marka;
														cout<<"Podaj model maszyny kt�rym chcesz siac"<<endl;
														cin>>marka;
														for(size_t i=0; i<garaz.size(); ++i)
														{
															maszyna_s* szt1=garaz.at(i);
															if(_stricmp(szt1->nazwa, nazwa)==0)
															{
																if(_stricmp(szt1->marka, marka)==0)
																{	
																	if(_stricmp(szt1->model, rasa)==0)
																	{
																		if(rand() %100==10)
																		{
																			szt1->stan=1;
																			cout<<"Traktor sie popsu�"<<endl;
																			system("pause");
																			break;
																		}
																	}
																	else
																	{
																		cout<<"Nie ma takiej maszyny"<<endl;
																		break;
																	}
																}
															}
														}
														cout<<"podaj marke siewnika kt�rym chcesz siac"<<endl;
														cin>>nazwa;
														for(size_t i=0; i<wiata.size(); ++i)
														{
															maszyna_z* szt2=wiata.at(i);
															if(_stricmp(szt2->nazwa, "siewnik")==0)
															{	
																if(_stricmp(szt2->marka, nazwa)==0)
																{										
																	if(rand() %100==10)
																	{
																		szt2->stan=1;
																		cout<<"siewnik sie popsu�"<<endl;
																		system("pause");
																		break;
																	}
																}
																else
																{
																	cout<<"Nie ma takiej maszyny"<<endl;
																	break;
																}
															}
														}
														szt->stan=3;
														bank=bank-szt->powierzchnia*(float(9)*float(4.5)+float(300));
														cout<<"Podaj nazwe uprawy"<<endl;
														cin>>szt->uprawa;
														cout<<"zasiano"<<endl;
													}
													break;
											case '4':
													if(szt->stan==1 || szt->stan==2 || szt->stan==3 || szt->stan==4 || szt->stan==5)
													{
														system("cls");	
														cout<<"Podaj nazwe maszyny kt�rym chcesz rozsiewac"<<endl;
														cin>>nazwa;
														cout<<"Podaj marke maszyny kt�rym chcesz rozsiewac"<<endl;
														cin>>marka;
														cout<<"Podaj model maszyny kt�rym chcesz rozsiewac"<<endl;
														cin>>marka;
														for(size_t i=0; i<garaz.size(); ++i)
														{
															maszyna_s* szt1=garaz.at(i);
															if(_stricmp(szt1->nazwa, nazwa)==0)
															{
																if(_stricmp(szt1->marka, marka)==0)
																{	
																	if(_stricmp(szt1->model, rasa)==0)
																	{
																		if(rand() %100==10)
																		{
																			szt1->stan=1;
																			cout<<"Traktor sie popsu�"<<endl;
																			system("pause");
																			break;
																		}
																	}
																	else
																	{
																		cout<<"Nie ma takiej maszyny"<<endl;
																		break;
																	}
																}
															}
														}
														cout<<"podaj marke rozsiewacza kt�rym chcesz rozsiewac nawoz"<<endl;
														cin>>nazwa;
														for(size_t i=0; i<wiata.size(); ++i)
														{
															maszyna_z* szt2=wiata.at(i);
															if(_stricmp(szt2->nazwa, "rozsiewacz")==0)
															{	
																if(_stricmp(szt2->marka, nazwa)==0)
																{										
																	if(rand() %100==10)
																	{
																		szt2->stan=1;
																		cout<<"rozsiewcz sie popsu�"<<endl;
																		system("pause");
																		break;
																	}
																}
																else
																{
																	cout<<"Nie ma takiej maszyny"<<endl;
																	break;
																}
															}
														}
														szt->stan=4;
														bank=bank-szt->powierzchnia*(float(2)*float(4.5)+float(300));
														cout<<"rozwieziono nawoz"<<endl;

													}
													break;
											case '5':
													if(szt->stan==3 || szt->stan==4 || szt->stan==5)
													{
														system("cls");	
														cout<<"Podaj nazwe maszyny kt�rym chcesz pryskac"<<endl;
														cin>>nazwa;
														cout<<"Podaj marke maszyny kt�rym chcesz pryskac"<<endl;
														cin>>marka;
														cout<<"Podaj model maszyny kt�rym chcesz pryskac"<<endl;
														cin>>marka;
														for(size_t i=0; i<garaz.size(); ++i)
														{
															maszyna_s* szt1=garaz.at(i);
															if(_stricmp(szt1->nazwa, nazwa)==0)
															{
																if(_stricmp(szt1->marka, marka)==0)
																{	
																	if(_stricmp(szt1->model, rasa)==0)
																	{
																		if(rand() %100==10)
																		{
																			szt1->stan=1;
																			cout<<"Traktor sie popsu�"<<endl;
																			system("pause");
																			break;
																		}
																	}
																	else
																	{
																		cout<<"Nie ma takiej maszyny"<<endl;
																		break;
																	}
																}
															}
														}
														cout<<"podaj marke opryskiwacza kt�rym chcesz pryskac"<<endl;
														cin>>nazwa;
														for(size_t i=0; i<wiata.size(); ++i)
														{
															maszyna_z* szt2=wiata.at(i);
															if(_stricmp(szt2->nazwa, "opryskiwacz")==0)
															{	
																if(_stricmp(szt2->marka, nazwa)==0)
																{										
																	if(rand() %100==10)
																	{
																		szt2->stan=1;
																		cout<<"opryskiwacz sie popsu�"<<endl;
																		system("pause");
																		break;
																	}
																}
																else
																{
																	cout<<"Nie ma takiej maszyny"<<endl;
																	break;
																}
															}
														}
														szt->stan=5;
														bank=bank-szt->powierzchnia*(float(2)*float(4.5)+float(100));
														cout<<"opryskano"<<endl;
													}
													break;		
											case '6':
													if(szt->stan==3 || szt->stan==4 || szt->stan==5)
													{
														system("cls");	
														cout<<"Podaj nazwe maszyny kt�rym chcesz zbirac plon"<<endl;
														cin>>nazwa;
														cout<<"Podaj marke maszyny kt�rym chcesz zbirac plon"<<endl;
														cin>>marka;
														cout<<"Podaj model maszyny kt�rym chcesz zbirac plon"<<endl;
														cin>>marka;
														for(size_t i=0; i<garaz.size(); ++i)
														{
															maszyna_s* szt1=garaz.at(i);
															if(_stricmp(szt1->nazwa, nazwa)==0)
															{
																if(_stricmp(szt1->marka, marka)==0)
																{	
																	if(_stricmp(szt1->model, rasa)==0)
																	{
																		if(rand() %100==10)
																		{
																			szt1->stan=1;
																			cout<<"Traktor sie popsu�"<<endl;
																			system("pause");
																			break;
																		}
																	}
																	else
																	{
																		cout<<"Nie ma takiej maszyny"<<endl;
																		break;
																	}
																}
															}
														}
														szt->stan=6;
														bank=bank-szt->powierzchnia*float(20)*float(4.5);
														bank=bank+szt->powierzchnia*float(4500);
														cout<<"zebrano plon"<<endl;
													}
													break;
											default:
													break;
										}
									}
									while(klawisz6!='Q');
								}
							}
							system("pause");
							break;
					default:
						break;
				}
				break;
		case '5':
				cout<<"Stan konta: "<<bank<<endl<<endl;
				for(size_t i=0; i<chlew.size(); ++i)
				{
					obsada* szt=chlew.at(i);
					cout<<szt->nazwa<<"		";
					cout<<szt->rasa<<"		";
					cout<<szt->plec<<"		";
					cout<<szt->wiek<<"		";
					cout<<szt->masa<<endl<<endl;
				}
				for(size_t i=0; i<garaz.size(); ++i)
				{
					maszyna_s* szt=garaz.at(i);
					cout<<szt->nazwa<<"		";
					cout<<szt->marka<<"		";
					cout<<szt->model<<"		";
					cout<<szt->rocznik<<"		";
					cout<<szt->moc<<endl<<endl;
				}
				for(size_t i=0; i<wiata.size(); ++i)
				{
					maszyna_z* szt=wiata.at(i);
					cout<<szt->nazwa<<"		";
					cout<<szt->marka<<"		";
					cout<<szt->model<<endl<<endl;
				}
				for(size_t i=0; i<grunt.size(); ++i)
				{
					ziemia* szt=grunt.at(i);
					cout<<szt->nrdzialki<<"		";
					cout<<szt->powierzchnia<<"		";
					cout<<szt->uprawa<<endl<<endl;
				}
				system("pause");
				break;
		default:
				break;
		}
	}
	while(klawisz1!='Q');


		for(size_t i=0; i<chlew.size(); ++i)
		{
			delete chlew.at(i);
			chlew.clear();
		}
		for(size_t i=0; i<garaz.size(); ++i)
		{
			delete garaz.at(i);
			garaz.clear();
		}
		for(size_t i=0; i<wiata.size(); ++i)
		{
			delete wiata.at(i);
			wiata.clear();
		}

	system("pause");
	return 0;
}