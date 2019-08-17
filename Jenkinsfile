pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'mkdir -p build && cd build'
        sh 'cmake ../'
        sh 'make'
      }
    }
    stage('Test') {
      steps {
        sh './build/test/sqrt_test'
      }
    }
    stage('Stirling Build') {
      when {
        branch 'stirling'
      }
      steps {
        echo 'Update stirling workspace and testing new features'
      }
    }
  }
}