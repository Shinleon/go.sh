import sys
import os
import csv

def init():

    csv_location = 'bin/go/go_data'
    csv_loc_true = os.path.join(os.path.expanduser('~'), csv_location)
    if not os.path.exists(csv_loc_true):
        os.mkdir(csv_loc_true)
    csv_name = 'directory_alias.csv'
    return os.path.join(os.path.expanduser('~'), csv_location, csv_name)

def in_csv(f_dir, alias):
    with open(f_dir, 'r') as inp:
        for row in csv.reader(inp):
            if row[0].strip() == alias:
                return row[1]
    return None

def add_to_csv(f_dir, alias, out_dir=os.getcwd()):
    if alias == "alias":
        return "cannot add an alias named \"alias\""
    temp_dir = in_csv(f_dir, alias)
    if type(temp_dir) == str:
        return f"Cannot add duplicate alias: \"{alias}\" tied to \"{temp_dir}\""
    with open(f_dir, 'a', newline='') as out:
        csv_writer = csv.writer(out, delimiter=',',
                        quotechar='|', quoting=csv.QUOTE_MINIMAL)
        csv_writer.writerow([alias, out_dir])
    return f"Added alias \"{alias}\" tied to \"{out_dir}\""

def rm_frm_csv(f_dir, alias):
    if alias == "alias":
        return "cannot remove an alias named \"alias\""
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
    ret = ""
    with open(f_dir, 'r') as inp:
        csv_reader = csv.reader(inp)
        for row in csv_reader:
            ret += str(row)
        ret += "   "
    return ret



def main():
    parameters = sys.argv[1:]

    if len(parameters) == 0:
        all_data = read_directories(storage_dir)
        print(all_data)
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
    


if __name__ == "__main__":
    storage_dir = init()
    if not os.path.exists(storage_dir):
        with open(storage_dir, 'w', newline='') as csvfile:
            spamwriter = csv.writer(csvfile, delimiter=',',
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
    main()
    sys.exit(0)
