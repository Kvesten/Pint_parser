// ЗАДАНИЕ: На плоскости задано множество точек А. Найти такую пару точек из А,
// что прямая, соеденяющая эти точки, пересекает минимальное количество других
// точек.
#include "MyFunc.h"
#include "include/settings/settings.h"
// #define DEBUG

int main(int argc, char const *argv[]) {
  auto *setings = new Settings(argc, argv);  // Парсим входные аргументы
  std::vector<Point *> vec_point;

  if (setings->use_file)
    pars_file(setings->filename, vec_point);

  // Если нет файла, то вводим ручками
  if (!setings->use_file) {
    bool f;
    do {
      f = 0;
      uint16_t mode;
      std::cout << "1. Ввести вручную.\n2. Ввести автоматически.\n3. Открыть "
                   "файл\n: ";
      std::cin >> mode;
      switch (mode) {
        case 1: human_input(vec_point); break;
        case 2: auto_input(vec_point); break;
        case 3: file_input(vec_point); break;

        default:
          std::cout << "Недопустимое значение, введите от 1 до 3" << std::endl;
          f = 1;
          break;
      }
    } while (f);
  }

  if (vec_point.size() < 3) {
    std::cerr << "нужно минимум 3 точки, у вас их: " << vec_point.size()
              << std::endl;
    return (-1);
  }

#ifdef DEBUG
  auto time = clock();
#endif  // DEBUG

  auto *out = parse_vector_point(vec_point);

#ifdef DEBUG
  auto time_end = double(clock() - time) / CLOCKS_PER_SEC;
  std::cout << time_end << std::endl;
#endif  // DEBUG

  print_min_max_line(*out);
  delete out;

  bool f;
  do {
    f = 0;
    char save_file;
    std::cout << "Сохранить файл с точками? [y/N]: ";
    std::cin.ignore();
    save_file = std::cin.get();
    if (save_file == '\n')
      save_file = 'N';
    switch (toupper(save_file)) {
      case 'Y': {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        save_from_file(vec_point, filename);
      } break;
      case 'N': break;
      default:
        std::cout << "Введите или n или y";
        f = 1;
        break;
    }
  } while (f);

  delete setings;
  for (auto &i : vec_point)
    delete i;
  vec_point.clear();
  std::cout << "Good End =)" << std::endl;
  return 0;
}
