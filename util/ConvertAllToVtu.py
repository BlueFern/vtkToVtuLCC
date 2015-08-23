# -*- coding: utf-8 -*-
"""
Batch script to convert a directory of vtk files to vtu files.
"""
import sys
import glob
import os

def main():
    if len(sys.argv) != 2:
        sys.exit("Expected argument: <directory containing vtk files>")
    
    if not os.path.isfile("ConvertVtkToVtu"):
        sys.exit("Provide a link to ConvertVtkToVtu in current directory")
        
    input_files = glob.glob(sys.argv[1] + "/*.vtk")
    for in_file in input_files:
        out_file = in_file[:-1] + 'u'
        args = "./ConvertVtkToVtu " + in_file + " " + out_file
        os.system(args)

if __name__ == "__main__":
    main()
