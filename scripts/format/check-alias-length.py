import sys

#argv[1] - --check option
#argv[2:] - files for fotmatting

def check_alias_length():
  files = sys.argv
  
  for file_path in files[2:]:
    str_count = 1
    file = open(file_path)
    line = file.readline()
    while line:
      if "typedef" in line:
        words = line.split()
        alias = words[2][:-1]
        if len(alias) < 3:
          print_warning(file_path, str_count)
      if "using" in line:
        words = line.split()
        alias = words[1]
        if len(alias) < 3:
          print_warning(file_path, str_count)

      line = file.readline()
      str_count += 1
    file.close()
  return

def print_warning(file_path, str_count):
  PURPLE = '\033[1;35m'
  BOLD = '\033[1;37m'
  RESET = '\033[0m'

  print(f'{BOLD}{file_path}:{str(str_count)}:', f'{PURPLE}warning:{RESET}',
        f'{BOLD}namespace alias should be at least 3 chars long{RESET}')
  return

def main():
  RED = '\033[1;31m'
  RESET = '\033[0m'

  files = sys.argv
  if len(files) <= 2:
    print(f'{RED}error:{RESET}', "no files for formatting")
    return
  if files[1] != "--check":
    print(f'{RED}error:{RESET}', "incorrect option")
    return
  
  check_alias_length()
  return

if __name__ == "__main__":
  main()
