import tensorflow as tf
import keras
import numpy as np
import csv
import sys 

def getDataFromCsv(fileName):
    inputs = []
    outputs = []
    with open(fileName) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
                # print(f'Column names are {", ".join(row)}')
                line_count += 1
            else:
                inputs.append([float(row[4]), float(row[5]), float(row[6]), float(row[7]),float(row[8]), float(row[9]), float(row[10]),float(row[11])])
                outputs.append([float(row[0]), float(row[1]), float(row[2]), float(row[3])]) 
                line_count += 1
    return inputs,outputs

inputs,outputs = getDataFromCsv('../data_outputs.csv')
# print(inputs[0])
#convert inputs and outputs to numpy arrays
inputs = np.array(inputs)
outputs = np.array(outputs)
#split data into training and testing sets
#create model
model = keras.Sequential()
#model contains input layer of size 4 and hidden layer of size 10 ,hidden layer has activation function relu and output layer has activation function sigmoid and loss function mean squared error and optimizer is adam optimizer with learning rate 0.01 and batch size of 10 and epochs of 1000  and validation split of 0.2 and shuffle is set to true and verbose is set to 1 and output layer has 4 nodes
model.add(keras.layers.Dense(32, activation='relu', input_shape=(8,)))
model.add(keras.layers.Dense(10, activation='sigmoid'))
model.add(keras.layers.Dense(4, activation='relu'))
model.compile(loss='mse', optimizer='adam', metrics=['mse'])
#fit model to training data
model.fit(inputs, outputs, epochs=1000, batch_size=10, validation_split=0.2, shuffle=True, verbose=1)
model.save('model.h5')