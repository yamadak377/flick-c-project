pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git branch: 'pixel8_p', url: 'https://github.com/yamadak377/flick-c-project.git'
            }
        }
        stage('Build') {
            steps {
                bat 'set PATH=C:\\Users\\user\\mingw64\\bin;%PATH% && make clean && make'
            }
        }
        stage('Test') {
            steps {
                bat '.\\c_flick_test.exe pixel8_p'
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: '*.exe', fingerprint: true
        }
    }
}
