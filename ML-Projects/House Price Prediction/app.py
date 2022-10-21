from flask import Flask, request, render_template
import model 

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/',methods=['POST'])
def predict():
    
    input_features = [x for x in request.form.values()]
    city=input_features[0]
    location=input_features[1]
    area_type=input_features[2]
    availability=input_features[3]
    total_sqft_int = input_features[4]
    bhk = input_features[5]
    bath = input_features[6]
    balcony = input_features[7]
    price_per_sqft = input_features[8]
    
    predicted_price = model.predict_house_price(bath,balcony,total_sqft_int,bhk,price_per_sqft,area_type,availability,location)       
    
    if city=='Mumbai':
        print("mum")
        predicted_price*=1.57
    elif city=='Delhi':
        print('del')
        predicted_price*=0.63    
    
    predicted_price=str(predicted_price)
    predicted_price=predicted_price[:5]
    
    return render_template('index.html', prediction_text='Estimated Price of House is {} Lakh'.format(predicted_price))

if __name__ == "__main__":
    app.run()
