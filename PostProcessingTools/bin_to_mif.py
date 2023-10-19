import sys

def bin_to_mif(binfile, miffile, width=32):
    with open(binfile, 'rb') as f_bin, open(miffile, 'w') as f_mif:
        f_mif.write('DEPTH = {};\n'.format(2**width))
        f_mif.write('WIDTH = {};\n'.format(width))
        f_mif.write('ADDRESS_RADIX = DEC;\n')
        f_mif.write('DATA_RADIX = BIN;\n')
        f_mif.write('CONTENT\nBEGIN\n')

        addr = 0
        byte = f_bin.read(1)
        while byte:
            f_mif.write('{} : {};\n'.format(addr, bin(int.from_bytes(byte, byteorder='big'))[2:].zfill(width)))
            addr += 1
            byte = f_bin.read(1)

        f_mif.write('END;\n')

bin_to_mif(sys.argv[1], sys.argv[1].replace('.bin', '.mif'))