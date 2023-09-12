// Derived from CesiumJS flight tracker demo

Cesium.Ion.defaultAccessToken = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiI2Y2E4MzM0MS0yNGVjLTQ1N2YtYmRlMi1kZTAwZDdjOTk2YmUiLCJpZCI6MTY0NjgyLCJpYXQiOjE2OTM5MjQ1NTZ9._BIZaMKGu6J7IrDajBnu4KzhNDWTBV3wUUTuPwslxpM';
const viewer = new Cesium.Viewer('cesiumContainer', {
    terrain: Cesium.Terrain.fromWorldTerrain(),
});

// TODO: Load location data
const flightData = JSON.parse(
    '[{"longitude":-114.39586,"latitude":45.11742,"height":700000},{"longitude":-114.28724,"latitude":45.22288,"height":700000},{"longitude":-114.1452,"latitude":45.36018,"height":700000},{"longitude":-114.03063,"latitude":45.47031,"height":700000},{"longitude":-113.91023,"latitude":45.56812,"height":700000},{"longitude":-113.77957,"latitude":45.67081,"height":700000},{"longitude":-113.65418,"latitude":45.76769,"height":700000},{"longitude":-113.52166,"latitude":45.86923,"height":700000},{"longitude":-113.39298,"latitude":45.9674,"height":700000},{"longitude":-113.25732,"latitude":46.07053,"height":700000},{"longitude":-113.12656,"latitude":46.16925,"height":700000},{"longitude":-112.99599,"latitude":46.26736,"height":700000},{"longitude":-112.85692,"latitude":46.37138,"height":700000},{"longitude":-112.72378,"latitude":46.47044,"height":700000},{"longitude":-112.59017,"latitude":46.56935,"height":700000},{"longitude":-112.45451,"latitude":46.66919,"height":700000},{"longitude":-112.40219,"latitude":46.7075,"height":700000},{"longitude":-112.18308,"latitude":46.86731,"height":700000},{"longitude":-112.04336,"latitude":46.9686,"height":700000},{"longitude":-111.91223,"latitude":47.07069,"height":700000},{"longitude":-111.78719,"latitude":47.17534,"height":700000},{"longitude":-111.65659,"latitude":47.28245,"height":700000},{"longitude":-111.52737,"latitude":47.38783,"height":700000},{"longitude":-111.39635,"latitude":47.49399,"height":700000},{"longitude":-111.26383,"latitude":47.60092,"height":700000},{"longitude":-111.13261,"latitude":47.70612,"height":700000},{"longitude":-110.9972,"latitude":47.81413,"height":700000},{"longitude":-110.86276,"latitude":47.92076,"height":700000},{"longitude":-110.72704,"latitude":48.02771,"height":700000},{"longitude":-110.59324,"latitude":48.13269,"height":700000},{"longitude":-110.45213,"latitude":48.24274,"height":700000},{"longitude":-110.29809,"latitude":48.36214,"height":700000},{"longitude":-110.15818,"latitude":48.46991,"height":700000},{"longitude":-110.01434,"latitude":48.58001,"height":700000},{"longitude":-109.87766,"latitude":48.68405,"height":700000},{"longitude":-109.73201,"latitude":48.79427,"height":700000},{"longitude":-109.59253,"latitude":48.89912,"height":700000},{"longitude":-109.4451,"latitude":49.00946,"height":700000},{"longitude":-109.29828,"latitude":49.12085,"height":700000},{"longitude":-109.15861,"latitude":49.22635,"height":700000},{"longitude":-109.00909,"latitude":49.33844,"height":700000},{"longitude":-108.86092,"latitude":49.44878,"height":700000},{"longitude":-108.71825,"latitude":49.55443,"height":700000},{"longitude":-108.56899,"latitude":49.66429,"height":700000},{"longitude":-108.42393,"latitude":49.77044,"height":700000},{"longitude":-108.27145,"latitude":49.88123,"height":700000},{"longitude":-108.1247,"latitude":49.98719,"height":700000},{"longitude":-107.97197,"latitude":50.09683,"height":700000},{"longitude":-107.82331,"latitude":50.20291,"height":700000},{"longitude":-107.68083,"latitude":50.30452,"height":700000},{"longitude":-107.47946,"latitude":50.46744,"height":700000},{"longitude":-107.34006,"latitude":50.57956,"height":700000},{"longitude":-107.20117,"latitude":50.69032,"height":700000},{"longitude":-107.06024,"latitude":50.80199,"height":700000},{"longitude":-106.91856,"latitude":50.91358,"height":700000},{"longitude":-106.7762,"latitude":51.02502,"height":700000},{"longitude":-106.63352,"latitude":51.136,"height":700000},{"longitude":-106.48335,"latitude":51.25195,"height":700000},{"longitude":-106.33897,"latitude":51.36282,"height":700000},{"longitude":-106.19385,"latitude":51.47346,"height":700000},{"longitude":-106.05192,"latitude":51.58099,"height":700000},{"longitude":-105.89882,"latitude":51.69621,"height":700000},{"longitude":-105.75058,"latitude":51.80705,"height":700000},{"longitude":-105.60936,"latitude":51.91196,"height":700000},{"longitude":-105.45824,"latitude":52.02352,"height":700000},{"longitude":-105.30106,"latitude":52.13869,"height":700000},{"longitude":-105.14606,"latitude":52.25153,"height":700000},{"longitude":-104.99657,"latitude":52.35965,"height":700000},{"longitude":-104.83852,"latitude":52.47313,"height":700000},{"longitude":-104.68841,"latitude":52.58019,"height":700000},{"longitude":-104.5369,"latitude":52.68745,"height":700000},{"longitude":-104.38322,"latitude":52.79568,"height":700000},{"longitude":-104.36918,"latitude":52.80551,"height":700000},{"longitude":-104.14574,"latitude":52.96129,"height":700000},{"longitude":-104.08882,"latitude":53.00075,"height":700000},{"longitude":-103.66236,"latitude":53.29321,"height":700000},{"longitude":-103.50163,"latitude":53.40198,"height":700000},{"longitude":-103.34328,"latitude":53.50841,"height":700000},{"longitude":-103.18163,"latitude":53.61635,"height":700000},{"longitude":-103.01807,"latitude":53.72468,"height":700000},{"longitude":-102.85287,"latitude":53.83333,"height":700000},{"longitude":-102.6947,"latitude":53.93663,"height":700000},{"longitude":-102.67634,"latitude":53.94859,"height":700000},{"longitude":-102.48911,"latitude":54.06987,"height":700000},{"longitude":-102.2399,"latitude":54.22977,"height":700000},{"longitude":-102.07179,"latitude":54.33659,"height":700000},{"longitude":-101.89569,"latitude":54.44769,"height":700000}]'
);
const timeStepInSeconds = 30;
const totalSeconds = timeStepInSeconds * (flightData.length - 1);
const start = Cesium.JulianDate.fromIso8601("2020-03-09T23:10:00Z");
const stop = Cesium.JulianDate.addSeconds(start, totalSeconds, new Cesium.JulianDate());
viewer.clock.startTime = start.clone();
viewer.clock.stopTime = stop.clone();
viewer.clock.currentTime = start.clone();
viewer.timeline.zoomTo(start, stop);
viewer.clock.multiplier = 50;
viewer.clock.shouldAnimate = true;

const positionProperty = new Cesium.SampledPositionProperty();

for (let i = 0; i < flightData.length; i++) {
    const dataPoint = flightData[i];

    const time = Cesium.JulianDate.addSeconds(start, i * timeStepInSeconds, new Cesium.JulianDate());
    const position = Cesium.Cartesian3.fromDegrees(dataPoint.longitude, dataPoint.latitude, dataPoint.height);
    positionProperty.addSample(time, position);

    viewer.entities.add({
    description: `Location: (${dataPoint.longitude}, ${dataPoint.latitude}, ${dataPoint.height})`,
    position: position,
    point: { pixelSize: 10, color: Cesium.Color.RED }
    });
}

// TODO: Update telemetry data
const dataPoint = flightData[flightData.length - 1];
document.getElementById("timeLabel").innerHTML = Cesium.JulianDate.addSeconds(start, (flightData.length - 1) * timeStepInSeconds, new Cesium.JulianDate());
document.getElementById("longitudeLabel").innerHTML = dataPoint.longitude;
document.getElementById("latitudeLabel").innerHTML = dataPoint.latitude;
document.getElementById("altitudeLabel").innerHTML = dataPoint.height / 1000;

// Load 3D model of cubesat
async function loadModel() {
    const model_uri = await Cesium.IonResource.fromAssetId(2267393);
    const sat_model = viewer.entities.add({
    availability: new Cesium.TimeIntervalCollection([ new Cesium.TimeInterval({ start: start, stop: stop }) ]),
    position: positionProperty,
    model: { uri: model_uri },
    orientation: new Cesium.VelocityOrientationProperty(positionProperty),    
    path: new Cesium.PathGraphics({ width: 3 })
    });
    viewer.trackedEntity = sat_model;
}

loadModel();

// TODO: Console input and log
var consoleInput = document.getElementById("consoleInput");
consoleInput.addEventListener("keypress", function(event) {
    if (event.key === "Enter") {
      const date = new Date();
      const consoleString = date.toISOString() + " [ground] : " + consoleInput.value + "\n";
      document.getElementById("consoleLog").innerHTML += consoleString;
      consoleInput.value = "";
    }
});