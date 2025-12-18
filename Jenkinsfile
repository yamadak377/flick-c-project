pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/yamadak377/flick-c-project.git'
            }
        }
        stage('Build') {
            steps {
                // MinGWのパスを通す（例: C:\mingw64\bin）
                bat 'set PATH=C:\\Users\\user\\mingw64\\bin;%PATH% && make clean && make'
            }
        }
        stage('Test') {
            steps {
                // 実行して結果を確認
                bat '.\\c_flick_test.exe pixel8a_p'
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: '*.exe', fingerprint: true
        }
    }
}
