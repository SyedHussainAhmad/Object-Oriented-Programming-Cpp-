//#include"String.h"
//
//int main()
//{
//	String m{ "Saramd mansoor cheema" };
//	ofstream ofs("cheema.txt", ios::binary);
//	int size = m.getLength() + 1;
//	ofs.write((char*)&size, sizeof(int));
//	ofs.write((char*)&m[0], size);
//	ofs.close();
//	String a;
//	int ts = 0;
//	ifstream ifs("cheema.txt", ios::binary);
//	ifs.read((char*)&ts, sizeof(int));
//	a.reSize(ts);
//	ifs.read((char*)&a[0], ts);
//	ifs.close();
//	cout << a << endl;
//}