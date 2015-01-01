#!/usr/bin/python

from sys import argv

# This script takes a text file containing a "note octave duration" sequence
# (one per line) and outputs LRFSound values which can be copied to an array in
# an .ino file. It assumes flat intonation and short rest duration.

# Valid notes       = [a-g]
# Valid octaves     = [1-8]
# Valid durations   = [s, ds, m, dm, l]

# I found it easier when creating music to write the text file and convert
# (rather than coding each note individually). You may want to refactor the
# array into multiple arrays when you have repeating structures to save your
# some lines in your .ino file (a to-do for this script).

# See http://www.littlerobotfriends.com/tutorial-01 for an example of what your
# final array should look like.

# Sample input file:
# c 3 l
# e 3 dm
# g 3 ds

__author__ = "Ethan Hart"
__date__ = "2014-12-31"


def readfile(filename):
    with open(filename, 'r') as inf:
        lines = inf.readlines()
    return lines


def create_lrf_sound(sound):
    dur_keys = {
        's': 'Short',
        'ds': 'DoubleShort',
        'm': 'Medium',
        'dm': 'DoubleMedium',
        'l': 'Long'
        }

    split = sound.split()
    note = split[0].upper()
    octave = split[1]
    duration = split[2]
    lrf_note = 'LRFNote_{0}'.format(note)
    lrf_oct = 'LRFOctave_{0}'.format(octave)
    lrf_dur = 'LRFDuration_{0}'.format(dur_keys[duration])

    lrf_sound = '{0}, {1}, LRFIntonation_Flat, {2}, LRFDuration_Short'
    lrf_sound = lrf_sound.format(lrf_note, lrf_oct, lrf_dur)

    return lrf_sound


def main():
    infile = argv[1]
    lines = readfile(infile)

    for l in lines:
        l = l.strip()
        if l.startswith("#"):  # Use '#' in text file to indicate new part
            print '\n' + l
        elif l != '':
            lrf_sound = create_lrf_sound(l)
            print '{ ' + lrf_sound + ' },'


if __name__ == "__main__":
    main()
