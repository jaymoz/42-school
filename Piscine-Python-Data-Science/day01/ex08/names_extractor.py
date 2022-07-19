import sys

def names_extractor(filename):
    with open(filename, "r") as input_file:
        with open('employees.tsv', 'w') as output_file:
            output_file.write('Name\tSurname\tE-mail\n')
            for line in input_file.readlines():
                name,surname = line.split('@')[0].split('.')
                name = name.capitalize()
                surname = surname.capitalize()
                output_file.write(f'{name}\t{surname}\t{line}')


if __name__=='__main__':
    if (len(sys.argv) == 2):
        names_extractor(sys.argv[1])
    else:
        raise Exception('Error arguments must be two')