## Установка и использование автоматических средств форматирования кода средствами clang-format и clang-tidy
В стандартных репозиториях Debian/Ubuntu последняя версия clang-format и других инструментов clang - 14. Чтобы установить более новую версию, нужно использовать скрипт с официального сайта llvm:
```
wget -O – https://apt.llvm.org/llvm.sh”
chmod +x llvm.sh
sudo ./llvm.sh 20
sudo apt install clang-format-20
sudo apt install clang-tidy-20
```
## Настройка clang-format и clang-tidy в VS Code

VS Code имеет встроенную поддержку clang-format, по умолчанию устанавливается clang-format style=file, что значит, что clang-format файл с ищется в текущей директории. Если файл не найден, используется стиль, установленный по умолчанию в `C_Cpp.clang_format_fallbackStyle`. Можно настроить исправление при сохранении, копировании и другие опции.

Расширение C/C++ от Microsoft имеет поддержку clang-tidy. Настройки указываются в `C_Cpp > Code Analysis > Clang Tidy:Config`. Если поле пусто, clang-tidy будет искать файл .clang-tidy в текущей директории. По умолчанию clang-tidy будет запускаться при открытии и сохранении файла, отображая результаты проверок clang-tidy. Можно настроить автоматическое исправление, разрешенные и запрещенные проверки и другие опции.

## Новые цели:

- `format-labid`: форматирование лабораторной программы с помощью clang-format, например
```
make format-alymova.ksenia/F0
```
Дополнительные параметры:

`--check`: отображение частей кода, отформатированных не по CG,

`--fix`: исправление кода, в соответствии с CG.

Параметры могут использованы отдельно или вместе. По умолчанию (без передачи параметров) выполняется режим check.

Для передачи дополнительных параметров используется переменная ARGS (при помощи GNU Make):
```
$ make format-alymova.ksenia/F0 ARGS="--check --fix"
```
или (с использоваием Bourne Shell):
```
$ ARGS="--check --fix" make format-alymova.ksenia/F0
```
или (Bourne Shell, с сохранением в окржении процесса):
```
$ export ARGS="--check --fix"
$ make alymova.ksenia/F0
```

- `tidy-labid`: статический анализ кода с помощью clang-tidy, например
```
make tidy-alymova.ksenia/F0
```
## Требуемые средства (для запуска не в Docker)
- clang-format версии >= 20
- clang-tidy версии >= 20
- python3

