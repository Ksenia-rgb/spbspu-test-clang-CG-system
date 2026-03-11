import sys

#argv[1] - --check option
#argv[2:] - files for fotmatting

def check_comments():
  files = sys.argv
  
  for file_path in files[2:]:
    str_count = 1
    file = open(file_path, 'r')
    line = file.readline()
    while line:
      if "//" in line or "/*" in line:
        print_warning(file_path, str_count)

      line = file.readline()
      str_count += 1
    file.close()
  return

def print_warning(file_path, str_count):
  PURPLE = '\033[1;35m'
  BOLD = '\033[1;37m'
  RESET = '\033[0m'

  print(f'{BOLD}{file_path}:{str(str_count)}:{RESET}',
        f'{PURPLE}warning:{RESET}', f'{BOLD}comments not allowed{RESET}')
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
  
  check_comments()
  return

if __name__ == "__main__":
  main()
