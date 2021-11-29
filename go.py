import sys
import os
import csv
import pathlib

def init():

    csv_location = 'bin/nav/nav_data'   # directory where csv lives
    csv_name = 'directory_alias.csv'  # csv file's name
    home = os.path.expanduser('~')

    csv_loc_true = os.path.join(home, csv_location)
    if not os.path.exists(csv_loc_true):
        os.mkdir(csv_loc_true)
    return os.path.join(home, csv_location, csv_name)

def in_csv(f_dir, alias):
    with open(f_dir, 'r') as inp:
        for row in csv.reader(inp):
            if row[0].strip() == alias:
                return row[1]
    return None

def add_to_csv(f_dir, alias, out_dir=os.getcwd()):
    temp_dir = in_csv(f_dir, alias)
    if type(temp_dir) == str:
        return f"Cannot add duplicate alias: \"{alias}\" tied to \"{temp_dir}\""
    with open(f_dir, 'a', newline='') as out:
        csv_writer = csv.writer(out, delimiter=',',
                        quotechar='|', quoting=csv.QUOTE_MINIMAL)
        csv_writer.writerow([alias, out_dir])
    return f"Added alias \"{alias}\" tied to \"{out_dir}\""

def rm_frm_csv(f_dir, alias):
    pairs = list()
    directory = None
    with open(f_dir, 'r') as inp:
        for row in csv.reader(inp):
            if row[0].strip() != alias:
                pairs.append(row)
            else:
                directory = row[1]
    with open(f_dir, 'w') as out:
        dir_writer = csv.writer(out, delimiter=',',
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
        for pair in pairs:
            dir_writer.writerow(pair)
    if directory == None:
        return f"Couldn't find alias of the name: \"{alias}\""
    return f"Removes alias \"{alias}\" tied to  \"{directory}\""

def read_directories(f_dir):
    ret = []
    max_alias_len = 0
    max_path_len = 0
    with open(f_dir, 'r') as inp:
        csv_reader = csv.reader(inp)
        for row in csv_reader:
            print(len(row))
            if len(row[0]) > max_alias_len:
                max_alias_len = len(row[0])
            if len(row[1]) > max_path_len:
                max_path_len = len(row[1])
            ret.append([row[0], row[1]])
    return ret, max_alias_len, max_path_len

def spaces(l):
    return ' '*l

def main():
    parameters = sys.argv[1:]

    if len(parameters) == 0:
        all_data, pad_alias, pad_path = read_directories(storage_dir)
        for data in all_data:
            print(
                data[0]+ spaces(pad_alias - len(data[0])) +
                spaces(4) + spaces(pad_path-len(data[1])) + 
                data[1], len(data))
    elif len(parameters) == 1:
        #print("We should move to", parameters[0])
        directory = in_csv(storage_dir, parameters[0])
        print(directory)
    else:
        #print("We're either adding or removing an alias.")
        if parameters[0] == "rm":
            msg = rm_frm_csv(storage_dir, parameters[1])
            print(msg)
        elif parameters[0] == "add":
            msg = add_to_csv(storage_dir, parameters[1])
            print(msg)
        else:
            print('Go only takes commands of \'add\' and \'rm\'.')

if __name__ == "__main__":
    storage_dir = init()
    if not os.path.exists(storage_dir):
        with open(storage_dir, 'w', newline='') as csvfile:
            spamwriter = csv.writer(csvfile, delimiter=',',
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
    elif os.path.exists(storage_dir):
        if not pathlib.Path(storage_dir).is_file():
            print(f'directory {storage_dir} isn\'t a file but it exists')
            sys.exit(1)
    main()

    sys.exit(0)
