//ͣ��������ϵͳ���
//һ����������
//��ͣ������һ����ͣ���������������������ƽ��������ֻ��һ�����ſɹ�����������
//����������ͣ�������������������ֻ�����������������ϵȺ�һ��ͣ�������г����ߣ������ڱ���ϵĵ�һ�������ɽ��롣
//ÿ��ͣ���ڳ����ĳ������뿪ͣ����ʱ���밴��ͣ����ʱ�䳤�̽��ɷ��á�
//����˵����
//1.����һ�������������ɻ��ˣ�ֻ�ܵȴ�����ͣ������
//2.�뿪���������ͣ��������ʼ��ʱ���뿪ͣ����ʱ�������뿪ʱ��ͽ���ʱ���Ʒѡ�
//3.�Ʒ���30����Ϊ�Ʒ����ڣ�ÿ30����1.5Ԫ��������15������ѣ�24Сʱ����շ�30Ԫ�ⶥ������Щ���ݿ�ά����
//
//��������Ҫ��
//1.������������Ҫ���복������Ϣ�����糵���ĳ��ƺ��롣
//2.�����ӱ������ͣ������Ҫ���복������Ϣ�����糵���ĳ��ƺ��롢�볡ʱ�䡢��ռ��λ��
//3.�����볡ʱ����Ҫ���복������Ϣ�����糵���ĳ��ƺ��롢�볡ʱ�䲢�Ʒѣ������г�����ʼ���������볡��
//4.�ƷѶ���ά����
//5.ͳ�ƹ��ܣ��������������ճ�λ�����������������ʱ������շ��ܶָ����������¼��
//6.��ѯ���ܣ������ڳ���λ�á�
//7.ά�����ܣ��Ʒѷ�ʽά����
//
//��������Ҫ��
//1.����������󷽷�����������������C++����ʵ��
//2.����רҵ�Ļ�ͼ���ߣ���Visio�ȣ�������ͼ������ͼ
//
//����Ҫ��
//ϵͳ�������ԡ���ά���ԣ�

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>

class Time
{
public:
	Time() = default;

	Time(char h, char m)
	{
		hour = h;
		minute = m;
	}

	void set_time(char h, char m)
	{
		hour = h;
		minute = m;
	}

	void show_info()
	{
		std::cout << hour << ":" << minute;
	}

	bool operator>=(Time time)
	{
		if (this->hour >= time.hour)
		{
			if (this->minute >= time.minute)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	int operator-(Time time)
	{
		return (this->hour - time.hour) * 60 + this->minute - time.minute;
	}

private:
	int hour;
	int minute;
};

class Place
{
public:
	Place() = default;

	Place(int _layer, int _row, int _col)
	{
		layer = _layer;
		row = _row;
		col = _col;
	}

	int get_layer()
	{
		return layer;
	}

	int get_row()
	{
		return row;
	}

	int get_col()
	{
		return col;
	}

	void set_layer(int _layer)
	{
		layer = _layer;
	}

	void set_row(int _row)
	{
		row = _row;
	}

	void set_col(int _col)
	{
		col = _col;
	}

private:
	int layer;
	int row;
	int col;
};

class CarInfo
{
public:
	void set_id(std::string _id)
	{
		id = _id;
	}

	void set_enter_time(Time time)
	{
		enter_time = time;
	}

	void set_valid(bool _valid)
	{
		valid = _valid;
	}

	std::string get_id()
	{
		return id;
	}

	Time get_enter_time()
	{
		return enter_time;
	}

	bool check_valid()
	{
		return valid;
	}

	void show_info()
	{
		std::cout << "id:" << id;
		std::cout << ", time ";
		enter_time.show_info();
		//std::cout << ", valid = " << valid;
		std::cout << "    ";
	}

private:
	std::string id;
	Time enter_time = { 0,0 };
	bool valid = false;
};

class Shortcut
{
public:
	void enter(std::string id)
	{
		if (cars.size() >= max)
		{
			std::cout << "����������޷�����!!!" << std::endl;
			return;
		}

		CarInfo new_car;
		new_car.set_id(id);
		cars.push(new_car);

		std::cout << "�������ɹ�����ǰ���������Ϊ" << cars.size() << std::endl;
	}

	void set_max(int val)
	{
		max = val;
	}

	CarInfo& get_front_info()
	{
		CarInfo& car = cars.front();
		return car;
	}

	void pop()
	{
		cars.pop();
	}

private:
	std::queue<CarInfo> cars;
	int max = 5;
};

class Park
{
public:
	Park()
	{
		cars.resize(layer);
		for (int i = 0; i < layer; i++)
		{
			cars[i].resize(row);
			for (int j = 0; j < row; j++)
			{
				cars[i][j].resize(col);
			}
		}
	}

	void enter(Shortcut& shortcut, int i, int j, int k)
	{
		CarInfo car = shortcut.get_front_info();
		shortcut.pop();

		car.set_valid(true);
		cars[i][j][k] = car;
	}

	void show_park()
	{
		for (int i = 0; i < layer; i++)
		{
			for (int j = 0; j < row; j++)
			{
				for (int k = 0; k < col; k++)
				{
					if (cars[i][j][k].check_valid())
						cars[i][j][k].show_info();
					else
						std::cout << "empty\t";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}

	bool check_valid(int _layer, int _row, int _col)
	{
		return _layer >= 0 && _layer < layer && _row >= 0 && _row < row && _col >= 0 && _col < col;
	}

	CarInfo* search(std::string _id)
	{
		for (int i = 0; i < layer; i++)
		{
			for (int j = 0; j < row; j++)
			{
				for (int k = 0; k < col; k++)
				{
					if (cars[i][j][k].get_id() == _id)
					{
						return &cars[i][j][k];
					}
				}
			}
		}
		return nullptr;
	}

	void out_of_part(std::string _id)
	{
		for (int i = 0; i < layer; i++)
		{
			for (int j = 0; j < row; j++)
			{
				for (int k = 0; k < col; k++)
				{
					if (cars[i][j][k].get_id() == _id)
					{
						cars[i][j][k].set_id(" ");
						cars[i][j][k].set_enter_time({ 0,0 });
						cars[i][j][k].set_valid(false);
					}
				}
			}
		}
	}

private:
	std::vector<std::vector<std::vector<CarInfo>>> cars;
	int layer = 3;
	int row = 3;
	int col = 3;
};

void menu()
{
	std::cout << "******************************************************************" << std::endl;
	std::cout << "***------------------------------------------------------------***" << std::endl;
	std::cout << "***--------------------   ͣ��������ϵͳ   --------------------***" << std::endl;
	std::cout << "***------------------------------------------------------------***" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	std::cout << "*************         0.�˳�ϵͳ                     *************" << std::endl;
	std::cout << "*************         1.���������������Ϣ         *************" << std::endl;
	std::cout << "*************         2.�����ӱ�����복��           *************" << std::endl;
	std::cout << "*************         3.�����뿪����                 *************" << std::endl;
	std::cout << "*************         4.��ʾ����ͣ����Ϣ             *************" << std::endl;
	std::cout << "*************         5.�ƷѶ���ά��                 *************" << std::endl;
	std::cout << "*************         6.��ʾ�ƷѶ���                 *************" << std::endl;
	std::cout << "******************************************************************" << std::endl;
}

int main()
{
	bool is_running = true;

	Shortcut shortcut;
	Park park;

	while (is_running)
	{
		menu();

		std::cout << "�����룺" << std::endl;
		int input;
		std::cin >> input;

		std::string car_id;
		Time enter_time;
		Time out_time;
		int h, m;
		int layer, row, col;
		
		int count_circle;		// �Ʒ����ڣ�����ÿ30���ӼƷ�һ��
		float price_per_circle;	// ÿ���Ʒ�������ȡ�ķ��ã�����ÿ30������ȡ1.5Ԫ
		int free_count_time;	// ��һ���Ʒ������ڳ�����ÿ�ʼ�Ʒѣ����粻����15�������
		float price_max;		// ����շѶ��٣�����30Ԫ�ⶥ

		float price = 0;

		// �˳�ϵͳ
		if (input == 0)
		{
			is_running = false;
			std::cout << "�˳��ɹ�" << std::endl;
		}
		// ���������������Ϣ
		else if (input == 1)
		{
			std::cout << "�����복�ƺ��룺";
			std::cin >> car_id;

			shortcut.enter(car_id);
		}
		// �����ӱ�����복��
		else if (input == 2)
		{
			CarInfo& car = shortcut.get_front_info();

			std::cout << "�볡���ƺ���Ϊ��" << car.get_id() << std::endl;

			std::cout << "�볡ʱ�䣺hour:";
			std::cin >> h;
			std::cout << "minute:";
			std::cin >> m;
			enter_time.set_time(h, m);

			std::cout << "��ռ��λ��";
			std::cout << "layer��";
			std::cin >> layer;
			std::cout << "row:";
			std::cin >> row;
			std::cout << "col:";
			std::cin >> col;

			if (!park.check_valid(layer, row, col))
			{
				std::cout << "����λ�ò��ڳ�����" << std::endl;
			}
			else
			{
				car.set_enter_time(enter_time);

				park.enter(shortcut, layer, row, col);

				park.show_park();
			}
		}
		// �����뿪����
		else if(input == 3)
		{
			std::cout << "������Ҫ�뿪�ĳ���id��";
			std::cin >> car_id;

			CarInfo* car = park.search(car_id);
			
			if (car == nullptr)
			{
				std::cout << "δ�ҵ���Ӧ����" << std::endl;
			}
			else
			{
				std::ifstream ifs_price("price.txt", std::ios::out);

				if (ifs_price.is_open())
				{
					ifs_price >> count_circle >> price_per_circle >> free_count_time >> price_max;

					ifs_price.close();
				}

				std::cout << "�볡ʱ�䣺hour:";
				std::cin >> h;
				std::cout << "minute:";
				std::cin >> m;
				out_time.set_time(h, m);

				enter_time = car->get_enter_time();

				int overall_minute;

				if (out_time >= enter_time)
				{
					overall_minute = out_time - enter_time;

					if (overall_minute % 30 >= 15)
					{
						price += 1.5;
					}
					overall_minute /= 30;
					price += 1.5 * overall_minute;
					if (price > 30)
						price = 30;

					std::cout << "��֧�����ã�" << price << std::endl;

					park.out_of_part(car_id);
				}
			}
		}
		// ��ʾ����ͣ����Ϣ
		else if (input == 4)
		{
			park.show_park();
		}
		// �ƷѶ���ά��
		else if (input == 5)
		{
			std::ofstream ofs_price("price.txt", std::ios::out);

			if (ofs_price.is_open())
			{
				std::cout << "�������޸ĺ�Ķ��۷���" << std::endl;
				std::cout << "�Ʒ�����" << std::endl;
				std::cin >> count_circle;
				std::cout << "�Ʒ���������ȡ�ķ���" << std::endl;
				std::cin >> price_per_circle;
				std::cout << "����ʱ�����������" << std::endl;
				std::cin >> free_count_time;
				std::cout << "�ⶥ�۸�" << std::endl;
				std::cin >> price_max;

				ofs_price << count_circle << " " << price_per_circle << " "
					<< free_count_time << " " << price_max << std::endl;

				ofs_price.close();

				std::cout << "д��ɹ�" << std::endl;
			}
		}
		// ��ʾ�ƷѶ���
		else if (input == 6)
		{
			std::ifstream ifs_price("price.txt", std::ios::out);

			if (ifs_price.is_open())
			{
				ifs_price >> count_circle >> price_per_circle >> free_count_time >> price_max;

				ifs_price.close();

				std::cout << "�Ʒ�����" << count_circle << std::endl;
				std::cout << "�Ʒ���������ȡ�ķ���" << price_per_circle << std::endl;
				std::cout << "����ʱ�����������" << free_count_time << std::endl;
				std::cout << "�ⶥ�۸�" << price_max << std::endl;
			}
		}

		system("pause");
		system("cls");
	}

	return 0;
}