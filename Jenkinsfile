pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh './jenkins/build.sh'
      }
    }
    stage('Test') {
      steps {
        sh './jenkins/test.sh'
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