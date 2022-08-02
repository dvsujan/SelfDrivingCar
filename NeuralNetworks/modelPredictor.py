import keras
import numpy as np
import socket
from server import Server

model = keras.models.load_model('model.h5')

def getPredictions(model, data):
    predictions = model.predict(data)
    return predictions

if __name__ == "__main__":
    #run server in loop to keep server running
    server = Server('127.0.0.1', 5001)
    while True:
        data = server.receive()
        if(data == 'exit'): break
        data = data.split(',')
        data = np.array(data, dtype=float)
        data = data.reshape(1, -1)        
        predictions = getPredictions(model, data)
        predictions = [round(x, 1) for x in predictions[0]]
        res = '' 
        
        for i in range(len(predictions)):
            if i == len(predictions) - 1:
                res += str(predictions[i])
            else:
                res += str(predictions[i]) + ','
        
        server.send(res)

print("server closed Successfully")





























# predictions = getPredictions(model,[[0,0,0,0]])

# #tst
# # print(inputs[100].reshape(1,4))
# #print predictions
# print("Predicted: ",predictions)
