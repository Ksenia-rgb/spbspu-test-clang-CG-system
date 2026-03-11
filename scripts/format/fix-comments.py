import sys

#argv[1] - --fix option
#argv[2:] - files for fotmatting

def fix_comments():
  files = sys.argv
  
  for file_path in files[2:]:
    temp_file = []
    file = open(file_path, 'r+')
    
    line = file.readline()
    while line:
      if not("//" in line or "/*" in line):
        temp_file.append(line)

      if "/*" in line:
        while line and not("*/" in line):
          line = file.readline()

      line = file.readline()
    file.seek(0)
    file.truncate()
    file.writelines(temp_file)
    file.close()
  return

def main():
  RED = '\033[1;31m'
  RESET = '\033[0m'

  files = sys.argv
  if len(files) <= 2:
    print(f'{RED}error:{RESET}', "no files for formatting")
    return
  if files[1] != "--fix":
    print(f'{RED}error:{RESET}', "incorrect option")
    return
  
  fix_comments()
  return

if __name__ == "__main__":
  main()
