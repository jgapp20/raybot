#!/bin/bash

#while true; do
  echo "Ejecutando codigo.py con límite de tiempo de 5 minutos..."
  timeout 5m python3 /home/raybot1/Documentos/ordenwhile.py
  echo "La ejecución de codigo.py ha finalizado."
  echo "Esperando 10 segundos antes de reiniciar..."
  sleep 10
#done

