import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix, classification_report 
from sklearn.metrics import ConfusionMatrixDisplay


def get_mnist_data():
    mnist_data = tf.keras.datasets.fashion_mnist
    (train_images, train_labels), (test_images, test_labels) = mnist_data.load_data()
    class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
                'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']

    train_images = train_images/255.0
    test_images = test_images/255.0
    return train_images, train_labels, test_images, test_labels

def build_model():
    model = tf.keras.Sequential([
                tf.keras.layers.Flatten(input_shape=(28,28)),
                tf.keras.layers.Dense(128, activation='relu'),
                tf.keras.layers.Dense(10)
            ])

    model.compile(optimizer='adam',
                loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
                metrics=['accuracy'])
    return model

def train_model(model, train_images, train_labels, epochs=20):
    model.fit(train_images, train_labels, epochs=epochs)

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
    train_images, train_labels, test_images, test_labels = get_mnist_data()
    model = build_model()
    train_model(model, train_images, train_labels)
    test_model(model, test_images, test_labels)
