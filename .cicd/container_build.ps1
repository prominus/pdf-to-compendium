<#
.DESCRIPTION
Quick and dirty builder for Docker containers
.SYNOPSIS
Quick and dirty builder for Docker containers
.PARAMETER Tag
Tag for the build
#>
param(
    [string] $Tag = "latest"
)
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser

docker build -t prominus001/typescript:$Tag -f typescript.Dockerfile .
docker build -t prominus001/emsdk_qpdf:$Tag -f emsdk.Dockerfile .