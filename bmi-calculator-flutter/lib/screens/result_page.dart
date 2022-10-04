import 'package:bmi_calculator/components/constants.dart';
import 'package:flutter/material.dart';
import '../components/reusable_card.dart';
import '../components/BottomButton.dart';
import 'input_page.dart';

class ResultPage extends StatelessWidget {
  //const ResultPage({Key? key}) : super(key: key);
  String results;
  String interpretation;
  String calculateBMI;
  ResultPage({@required this.results,@required this.interpretation,@required this.calculateBMI});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          'BMI CALCULATOR',
        ),
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          Expanded(
            child: Container(
              child: Text(
                'Your Results',
                style: kResultText,
              ),
            ),
          ),
          Expanded(
              flex: 5,
              child: ReusableCard(
                colour: kActiveCardColour,
                cardChild: Column(
                  crossAxisAlignment: CrossAxisAlignment.center,
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Text(
                      results,
                      style: TextStyle(
                        fontSize: 22,
                        fontWeight: FontWeight.bold,
                        color: Color(0xff24d876),
                      ),
                    ),
                    Text(
                      calculateBMI,
                      style: TextStyle(
                        fontSize: 100,
                        fontWeight: FontWeight.bold,
                        color: Color(0xffffffff),
                      ),
                    ),
                    Text(
                      interpretation,
                      textAlign: TextAlign.center,
                      style: TextStyle(
                        fontSize: 22,
                        color: Color(0xffffffff),
                      ),
                    ),
                  ],
                ),
              ),
            ),
          BottomButton(
            text: 'RE-CALCULATE',
            onTap: ()
            {
              Navigator.pop(context, MaterialPageRoute(builder: (context)
              {
                return InputPage();
              },
                ),
              );
            },
          ),
        ],
      ),
    );
  }
}
