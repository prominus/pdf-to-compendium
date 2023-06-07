<#
.DESCRIPTION
Quick and dirty builder for Docker containers
.SYNOPSIS
Quick and dirty builder for Docker containers
.PARAMETER Tag
Tag for the build
.PARAMETER Target
Target for the build
#>
param(
    [string] $Tag = "latest",
    [string] $Target = "base"
)
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser

docker build --target $Target -t prominus001/typescript:$Tag -f typescript.Dockerfile .
docker build --target $Target -t prominus001/gcc13_emsdk:$Tag -f gcc13_emsdk.Dockerfile .