import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import '../components/reusable_card.dart';
import '../components/showing_icon.dart';
import '../components/constants.dart';
import '../components/BottomButton.dart';
import 'package:bmi_calculator/calculatorBrain.dart';
import 'result_page.dart';

enum Gender {
  male,
  female,
}


Gender selectedGender;

class InputPage extends StatefulWidget {
  @override
  _InputPageState createState() => _InputPageState();
}


class _InputPageState extends State<InputPage> {
  int height = 170;
  int weight = 60;
  int age=21;

  @override
  Widget build(BuildContext context) {
    return Builder(
      builder: (context) {
        return Scaffold(
          appBar: AppBar(
            title: Text('BMI CALCULATOR'),
          ),
          body: Column(
            children: <Widget>[
              Expanded(
                child: Row(
                  children: [
                    Expanded(
                      child: ReusableCard(
                        onpress: () {
                          setState(
                            () {
                              print('male card is pressed!');
                              selectedGender = Gender.male;
                            },
                          );
                        },
                        colour: selectedGender == Gender.male
                            ? kActiveCardColour
                            : kInactiveCardColour,
                        cardChild: ShowingIcon(
                          setIcon: FontAwesomeIcons.mars,
                          setText: 'MALE',
                        ),
                      ),
                    ),
                    Expanded(
                      child: ReusableCard(
                        onpress: () {
                          setState(
                                () {
                              print('female card is pressed!');
                              selectedGender = Gender.female;
                            },
                          );
                        },
                        colour: selectedGender == Gender.female
                            ? kActiveCardColour
                            : kInactiveCardColour,
                        cardChild: ShowingIcon(
                          setIcon: FontAwesomeIcons.venus,
                          setText: 'FEMALE',
                        ),
                      ),
                    ),
                  ],
                ),
              ),
              Expanded(
                child: ReusableCard(
                  colour: kActiveMidContainerColour,
                  cardChild: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text(
                        'HEIGHT',
                        style: kLabelTextStyle,
                      ),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        crossAxisAlignment: CrossAxisAlignment.baseline,
                        textBaseline: TextBaseline.alphabetic,
                        children: [
                          Text(
                            height.toString(),
                            style: kNumberTextStyle,
                          ),
                          Text(
                            'cm',
                            style: kLabelTextStyle,
                          )
                        ],
                      ),
                      SliderTheme(
                        data: SliderTheme.of(context).copyWith(
                          activeTrackColor: Colors.white,
                          inactiveTrackColor: Color(0xff8d8e98),
                          thumbShape: RoundSliderThumbShape(enabledThumbRadius: 15),
                          thumbColor: Color(0xffeb1555),
                          overlayShape: RoundSliderOverlayShape(overlayRadius: 24),
                          overlayColor: Color(0x29eb1555)
                        ),
                        child: Slider(
                          min: 120.0,
                          max: 220.0,
                          value: height.toDouble(),
                          onChanged: (double newValue) {
                            setState(
                              () {
                                //height = value.toInt();
                                height = newValue.round();
                              },
                            );
                          },
                        ),
                      )
                    ],
                  ),
                ),
              ),
              Expanded(
                child: Row(
                  children: [
                    Expanded(
                      child: ReusableCard(colour: kActiveLastContainerColour,
                        cardChild: Column(
                          children: [
                            Text(
                                'WEIGHT',
                              style: kLabelTextStyle,
                            ),
                            Text(
                              weight.toString(),
                              style: kNumberTextStyle,
                            ),
                            Row(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: [
                                RoundIconButton(
                                  icon: FontAwesomeIcons.minus,
                                  onPressed: (){
                                    setState(() {
                                      weight>0?weight--: weight=0;
                                    });
                                  },
                                ),
                                SizedBox(width: 10.0),
                                RoundIconButton(icon: FontAwesomeIcons.add,
                                  onPressed: (){
                                  setState(() {
                                    weight++;
                                  });
                                },
                                ),
                              ],
                            )
                          ],
                        ),
                      ),
                    ),
                    Expanded(
                      child: ReusableCard(colour: kActiveLastContainerColour,
                      cardChild: Column(
                        children: [
                          Text(
                            'AGE',
                            style: kLabelTextStyle,
                          ),
                          Text(
                            age.toString(),
                            style: kNumberTextStyle,
                          ),
                          Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: [
                              RoundIconButton(
                                icon: FontAwesomeIcons.minus,
                                onPressed: (){
                                  setState(() {
                                    age>0?age--: age=0;
                                  });
                                },
                              ),
                              SizedBox(width: 10.0),
                              RoundIconButton(icon: FontAwesomeIcons.add,
                                onPressed: (){
                                  setState(() {
                                    age++;
                                  });
                                },
                              ),
                            ],
                          )
                        ],
                      ),
                      ),
                    ),
                  ],
                ),
              ),
              BottomButton(text: 'CALCULATE',
              onTap: ()
              {
                CalculatorBrain calc=CalculatorBrain(weight: weight,height: height);

                Navigator.push(context, MaterialPageRoute(builder: (context)
                    {
                      return ResultPage(calculateBMI: calc.calculateBMI(),interpretation: calc.getInterpretation(),results: calc.getResult(),);
                    }
                ),
                );
              },
              ),
            ],
          ),
        );
      },
    );
  }
}



class RoundIconButton extends StatelessWidget {

  final IconData icon;
  final Function onPressed;

  RoundIconButton({ this.icon, this.onPressed});

  @override
  Widget build(BuildContext context) {
    return RawMaterialButton(
      onPressed: onPressed,
      child: Icon(
        icon,
      ),
      fillColor: Color(0xff1d1f33),
      shape: CircleBorder(),
      constraints: BoxConstraints.tightFor(
          width: 56.0,
          height: 56.0
      ),
    );
  }
}


