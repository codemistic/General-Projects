import 'package:cached_network_image/cached_network_image.dart';
import 'package:flutter/material.dart';
import 'package:get/get_state_manager/src/simple/get_state.dart';
import 'package:get/get_state_manager/src/simple/get_view.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:epic_weather/app/data/models/temperature_model.dart';
import 'package:epic_weather/app/modules/home/controllers/home_controller.dart';

class TemperatureChart extends GetView<HomeController> {
  @override
  Widget build(BuildContext context) {
    return GetBuilder<HomeController>(builder: (controller) {
      final chart = SfCartesianChart(
          plotAreaBorderWidth: 0,
          tooltipBehavior: TooltipBehavior(
            color: controller.theme.appColorTheme.colorBackground,
            enable: true,
            builder: (data, point, series, pointIndex, seriesIndex) {
              return indicator(
                  data: data, controller: controller, context: context);
            },
          ),
          enableSideBySideSeriesPlacement: false,
          primaryXAxis: CategoryAxis(
              labelStyle: controller.theme.appTextTheme.txt12white.copyWith(
                  fontSize: 6,
                  fontFamily: 'ReemKufi',
                  color: controller.theme.appColorTheme.greyButtonInsideColor,
                  height: 1.4),
              crossesAt: controller.appSettings.isCelciuis
                  ? (controller.lowestTemperature - 273).ceil() - 5
                  : ((controller.lowestTemperature - 273) * (9 / 5) + 32)
                          .ceil() -
                      5,
              majorGridLines: MajorGridLines(width: 0),
              minorGridLines: MinorGridLines(width: 0),
              majorTickLines: MajorTickLines(size: 0),
              axisLine: AxisLine(width: 0),
              labelPlacement: LabelPlacement.onTicks),
          primaryYAxis: NumericAxis(
            labelStyle: controller.theme.appTextTheme.txt12white.copyWith(
              fontSize: 6,
              color: controller.theme.appColorTheme.greyButtonInsideColor,
              fontFamily: 'ReemKufi',
            ),
            majorGridLines: MajorGridLines(width: 0, color: Colors.transparent),
            minorGridLines: MinorGridLines(width: 0, color: Colors.transparent),
            minimum: controller.appSettings.isCelciuis
                ? (controller.lowestTemperature - 273).ceil().toDouble() - 5
                : ((controller.lowestTemperature - 273) * (9 / 5) + 32)
                        .ceil()
                        .toDouble() -
                    5,
            maximum: controller.appSettings.isCelciuis
                ? (controller.highestTemperature - 273).ceil().toDouble() + 5
                : ((controller.highestTemperature - 273) * (9 / 5) + 32)
                        .ceil()
                        .toDouble() +
                    5,
            axisLine: AxisLine(width: 0),
            edgeLabelPlacement: EdgeLabelPlacement.shift,
            labelFormat:
                controller.appSettings.isCelciuis ? '{value}°C' : '{value}°F',
            majorTickLines: MajorTickLines(size: 0),
          ),
          series: <ChartSeries<TemperatureChartData, String>>[
            SplineAreaSeries<TemperatureChartData, String>(
                onRendererCreated: (chartController) {
                  controller.chartController = chartController;
                },
                animationDuration: 600,
                borderWidth: 4,
                borderColor: controller.theme.appColorTheme.graphBorderColor,
                color: controller.theme.appColorTheme.graphColor,
                dataSource: controller.chartData,
                xValueMapper: (TemperatureChartData temp, _) => temp.time,
                yValueMapper: (TemperatureChartData temp, _) => controller
                        .appSettings.isCelciuis
                    ? (temp.temperature - 273).ceilToDouble()
                    : ((temp.temperature - 273) * (9 / 5) + 32).ceilToDouble(),
                markerSettings: MarkerSettings(isVisible: false),
                // Enable data label
                dataLabelSettings: DataLabelSettings(
                  isVisible: true,
                  textStyle: controller.theme.appTextTheme.txt18grey
                      .copyWith(fontFamily: 'ReemKufi', fontSize: 12),
                )),
          ]);
      return chart;
    });
  }

  Widget indicator(
      {required TemperatureChartData data,
      required HomeController controller,
      required BuildContext context}) {
    return FittedBox(
      child: Container(
        padding: EdgeInsets.all(10),
        decoration: BoxDecoration(
            boxShadow: [controller.theme.appColorTheme.shadowMedium],
            color: controller.theme.appColorTheme.colorBackground,
            borderRadius: BorderRadius.circular(10)),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Image.asset(
              controller.theme.appPngImages.getWeatherIcon(data.weatherIcon),
              height: 50,
            ),
            Container(
              margin: EdgeInsets.only(top: 30),
              child: Text(
                controller.appSettings.isCelciuis
                    ? (data.temperature - 273).ceil().toString() + "°c"
                    : ((data.temperature - 273) * (9 / 5) + 32)
                            .ceil()
                            .toString() +
                        "°f",
                style: controller.theme.appTextTheme.txt18grey
                    .copyWith(fontSize: 32, height: 0.1),
              ),
            ),
            Text(
              data.time.toString(),
              style: controller.theme.appTextTheme.txt18grey
                  .copyWith(fontSize: 10),
              textAlign: TextAlign.center,
            ),
            Text(
              data.weather,
              style: controller.theme.appTextTheme.txt18grey
                  .copyWith(fontSize: 10),
              textAlign: TextAlign.center,
            )
          ],
        ),
      ),
    );
  }
}
