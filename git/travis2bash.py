import yaml

def write_byte(f, string):
    f.write(string.encode())

    
def convert(travis_yaml):
    with open(travis_yaml, 'r') as yaml_file:
        config = yaml.safe_load(yaml_file) 
    
    with open("travis_script.sh", 'wb') as out:    
        print(config["env"])
        write_byte(out, "#!/bin/bash\n\n\n")
        
        write_byte(out, "set -ex\n")
        write_byte(out, "export CC=gcc\n")
        
        write_byte(out, "#env\n\n") 
            
        def write_env(name):
            write_byte(out, "\n")
            write_byte(out, "#env: %s\n"%(name))
            for env in config["env"][name]:
                write_byte(out, "export %s\n"%(env))
            write_byte(out, "\n")
        
        for item in config["env"]:               
            write_env(item)
        
        def write_cmd(name):
            if name not in config:
                return
            
            write_byte(out, "\n#" + name + "\n")
            for cmd in config[name]:
                write_byte(out, cmd)
                write_byte(out, "\n")
            write_byte(out, "\n")
            
        #print(config["before_install"])
        write_cmd("before_install")
        write_cmd("install")
        write_cmd("before_script")
        write_cmd("script")
              

if __name__ == "__main__":
    #convert("travis.yml")
    convert("stream_travis.yml")
    print("end")
