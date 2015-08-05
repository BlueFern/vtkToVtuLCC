# -*- coding: utf-8 -*-
"""
Created on Wed Aug  5 12:33:31 2015

@author: sed59
"""
import sys
import glob
import os


def main():
    
    if len(sys.argv) != 2:
        sys.exit("Requires directory of vtk files")
    
    if not os.path.isfile("ConvertVtkToVtu"):
        sys.exit("Provide a link to ConvertVtkToVtu in current directory")
        
    base_files = glob.glob(sys.argv[1] + "/*.vtk")
    for filename in base_files:
        output_file = filename[:-1] + 'u'
        args = "./ConvertVtkToVtu " + filename + " " + output_file
        os.system(args)

if __name__ == "__main__":
    main()
