#include "MyFunc.h"

// На вход имя файла с точками и вектор куда они будут записаны
void pars_file(const std::string &filename, std::vector<Point *> &vec) {
  std::ifstream f;
  f.open(filename);
  if (f.is_open()) {
    std::string tmp_line;
    while (!f.eof() and getline(f, tmp_line)) {
      std::string x(tmp_line, 0, tmp_line.find(" ")),
          y(tmp_line, tmp_line.find(" ") + 1, tmp_line.length());
      Point *tmp = new Point(stoi(x), stoi(y));
      vec.push_back(tmp);
    }
    f.close();
  } else
    std::cerr << "Ошибка чтения файла \"" << filename << "\"" << std::endl;
}

void human_input(std::vector<Point *> &vec) {
  std::cout << "Введите количество точек (целое положительное число!): ";
  size_t count;
  std::cin >> count;
  std::cout << "Координаты X и Y точек:\nПример: \"2 -5\"" << std::endl;
  for (size_t i = 0; i < count; i++) {
    std::cout << "№" << i + 1 << ": ";
    int32_t x, y;
    ;
    std::cin >> x >> y;
    Point *tmp = new Point(x, y);
    vec.push_back(tmp);
  }
}

void auto_input(std::vector<Point *> &vec) {
  std::cout << "Введите количество точек (целое положительное число!): ";
  size_t count;
  std::cin >> count;
  for (size_t i = 0; i < count; i++) {
    Point *tmp = new Point(std::rand(), std::rand());
    vec.push_back(tmp);
  }
}

void file_input(std::vector<Point *> &vec) {
  std::string filename;
  std::cout << "Введите имя файла: ";
  std::cin >> filename;
  pars_file(filename, vec);
}

// Поиск элементов подходящий под условие задачи
Min_max_line *parse_vector_point(const std::vector<Point *> &vec) {  // Ужас
  auto *out = new Min_max_line;
  out->min.count_point = UINT16_MAX;
  for (auto i = vec.begin(); i != vec.end(); i++) {
    for (auto j = i; j != vec.end(); j++) {
      if (**j == **i)
        continue;
      size_t tmp = 0;
      for (auto &k : vec) {
        if (*i != *j and *j != k and k != *i)
          tmp += ((*j)->y - (*i)->y) * (k->x - (*i)->x) ==
                 ((*j)->x - (*i)->x) * (k->y - (*i)->y);
      }
      if (tmp and tmp < out->min.count_point) {
        out->min.count_point = tmp;
        out->min.point1 = *i;
        out->min.point2 = *j;
      }
      if (tmp > out->max.count_point) {
        out->max.count_point = tmp;
        out->max.point1 = *i;
        out->max.point2 = *j;
      }
    }
  }
  return out;
}

void print_min_max_line(const Min_max_line &out) {
  if (out.min.count_point == UINT16_MAX)
    std::cout
        << "Нету линии на которой будет хоть 1 точка, которая не образует её.";
  else {
    std::cout << "Точки на линии которых лежит меньше всего точек это:\nX: "
              << out.min.point1->x << "\tY: " << out.min.point1->y
              << "\nX: " << out.min.point2->x << "\tY: " << out.min.point2->y
              << "\nКоличество точек лежащее на этой линии: "
              << out.min.count_point << '\n';
    if (out.max.count_point != 0)
      std::cout << "Точки на линии которых лежит больше всего точек это:\nX: "
                << out.max.point1->x << "\tY: " << out.max.point1->y
                << "\nX: " << out.max.point2->x << "\tY: " << out.max.point2->y
                << "\nКоличество точек лежащее на этой линии: "
                << out.max.count_point << '\n';
  }
}

// Сохраняет вектор точек в файл
void save_from_file(const std::vector<Point *> &vec,
                    const std::string &filename) {
  std::ofstream file(filename);
  if (file) {
    for (auto &i : vec)
      file << i->x << ' ' << i->y << '\n';
    file.close();
  } else {
    std::cerr << "Ошибка открытия файла \"" << filename << "\" на запись"
              << std::endl;
  }
}
