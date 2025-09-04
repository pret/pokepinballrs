'init_gfx_json.py'
* For reading a folder and building an initial json file for the .4bpp files in it.
* This prepopulates a tilecount, which can be useful for ballpark sizing the height/width
* Run this in the folder with the graphics to be loaded into the json file
* If a file with a .gbapal with the same name as the .4bpp file exists, it will automatically load that in as that file's palette.


'convert.py'
* For reading a json graphics config file, and calling the conversion process as a loop.
* Called with convert.py {path to gbagfx} {path to json file} --direction {to-png or to-4bpp}
* Conversion uses the json settings for both direction of conversion, needing the mheight/mwidth/oam to handle some of these entries


'prune.py'
* For 'trimming' a number of blank tiles off the end of a .4bpp file, to account for those stray extra 0x20 * x bits at the end.
* This saves an original copy of the .4bpp file, which it uses as the base when re-running this script on the same file.
* Called with prune.py {path to .4bpp file} {tiles to remove}


'split_gfx'
* For splitting .4bpp files that are easier parsed as a series of sub images.
* This creates new files with the name being the {filename}_{suffix}.4bpp
* Called with split_gfx.py {path to file} {suffix} {tiles to skip} {tiles to take}
* Sample from pulling the link_gbasp segment out of sprites.4bpp (tool and byte file in the same folder being run from): 
   split_gfx.py sprites.4bpp link_gbasp 768 18
  *this creates a sprites_link_gbasp.4bpp file.