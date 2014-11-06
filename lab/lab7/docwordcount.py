import sys
import re

from pyspark import SparkContext

def flat_map(document):
    """
    Takes in document, which is a key, value pair, where document[0] is the
    document ID and document[1] is the contents of the document.
    """
    """ Your code here. """
    words = re.findall(r"\w+", document[1])
    unique = []
    for word in words:
        if word not in unique:
            unique.append(word)
    return unique
    #return set(words)

def map(arg):
    """ Your code here. """
    return (arg, 1)

def reduce(arg1, arg2):
    """ Your code here. """
    # args are values
    return arg1 + arg2

def docwordcount(file_name, output="spark-wc-out-docwordcount"):
    sc = SparkContext("local[8]", "DocWordCount")
    file = sc.sequenceFile(file_name)

    counts = file.flatMap(flat_map) \
                 .map(map) \
                 .reduceByKey(reduce) \
                 .sortByKey()

    counts.coalesce(1).saveAsTextFile(output)

""" Do not worry about this """
if __name__ == "__main__":
    argv = sys.argv
    if len(argv) == 2:
        docwordcount(argv[1])
    else:
        docwordcount(argv[1], argv[2])
