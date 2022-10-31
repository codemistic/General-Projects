import tensorflow as tf
# from tensorflow import keras
from tensorflow.keras import datasets, layers, models
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix, classification_report 
from sklearn.metrics import ConfusionMatrixDisplay
import numpy as np

def build_cnn_model():
    model = models.Sequential()
    model.add(layers.Conv2D(32,(3,3),activation='relu',input_shape=(32,32,3)))
    model.add(layers.MaxPooling2D((2,2)))
    model.add(layers.Conv2D(64,(3,3),activation='relu'))
    model.add(layers.MaxPooling2D((2,2)))
    model.add(layers.Conv2D(64,(3,3),activation='relu'))
    model.add(layers.Flatten())
    model.add(layers.Dense(64,activation='relu'))
    model.add(layers.Dense(10))
    print(model.summary())
    return model

def train_model(model, train_images, train_labels, test_images, test_labels):
    model.compile(optimizer='adam', loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True), metrics=['accuracy'])
    history = model.fit(train_images, train_labels, epochs=10, validation_data=(test_images, test_labels))

def test_model(model, test_images, test_labels):
    test_loss, test_acc = model.evaluate(test_images, test_labels, verbose=2)
    print('Test Data Accuracy: ',test_acc)
    print('Test Data Loss: ',test_loss)

    #converting model to output probabilities of each of the classes defined
    probability_model = tf.keras.Sequential([model, 
                                            tf.keras.layers.Softmax()])
    predictions_prob = probability_model.predict(test_images)      
    predictions = [np.argmax(prediction) for prediction in predictions_prob]  
    # print(len(predictions))
    # print(len(test_labels))            
    cm = tf.math.confusion_matrix(
            test_labels,
            predictions,
            num_classes=None,
            #[0,1,2,3,4,5,6,7,8,9]
            weights=None,
            dtype=tf.dtypes.int32,
            name=None
        )  
    print('**************************Confusion Matrix***********************************')                      
    print(cm) 
    cm = confusion_matrix(test_labels, predictions)
    print('**************************Classification Report***********************************')
    print(classification_report(test_labels, predictions))
    ConfusionMatrixDisplay(cm).plot()
    plt.show()

if __name__=='__main__':
    (train_images, train_labels), (test_images, test_labels) = datasets.cifar10.load_data()
    train_images, test_images = train_images/255.0, test_images/255.0
    model = build_cnn_model()
    train_model(model, train_images, train_labels, test_images, test_labels)
    test_model(model, test_images, test_labels)