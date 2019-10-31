var app=angular.module("myCalc",[]);
app.controller("calcCtrl", function ($scope)
{
    $scope.add=function()
    {
        var a=Number ($scope.first);
        var b=Number ($scope.second);
        $scope.result=a+b;
    };
    $scope.sub=function()
    {
        var a=Number ($scope.first);
        var b=Number ($scope.second);
        $scope.result=a-b;
    };
    
});